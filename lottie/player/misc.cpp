
// functions

int stringToInt(string inputString) {
	stringstream streamer(inputString);
	int outputInt;
	streamer >> outputInt;
	return outputInt;
}

float stringToFloat(string inputString) {
	stringstream streamer(inputString);
	float outputFloat;
	streamer >> outputFloat;
	return outputFloat;
}

bool keyFound(struct KeyValue* tempKeyValue, string key) {
	if (tempKeyValue != NULL) {
		if (strlen(tempKeyValue->key) != 0) {
			if (strcmp(tempKeyValue->key, key.c_str()) == 0) {
				return true;
			}
		}
	}
	return false;
}

struct KeyValue* addChildArray(struct KeyValue* traceKeyValue) {
	//EM_ASM({console.log("addingchildarray 901.1");});
	struct ArrayOfString* tempArrayOfString;
	tempArrayOfString = new ArrayOfString;
	//EM_ASM({console.log("addingchildarray 901.5");});
	if (traceKeyValue == NULL) {
		traceKeyValue = new KeyValue;
		traceKeyValue->start = traceKeyValue;
		traceKeyValue->arrayValue = tempArrayOfString;
		traceKeyValue->arrayValue->root = tempArrayOfString;
		return traceKeyValue;
	}
	if (traceKeyValue->arrayValue == NULL) {
		//EM_ASM({console.log("addingchildarray 901.9");});
		traceKeyValue->arrayValue = tempArrayOfString;
		traceKeyValue->arrayValue->root = tempArrayOfString;
		return traceKeyValue;
	}
	//EM_ASM({console.log("addingchildarray 901.10");});

	tempArrayOfString->root = traceKeyValue->arrayValue->root;
	//EM_ASM({console.log("addingchildarray 901.15");});
	if (traceKeyValue->arrayValue->vector == NULL) {
		traceKeyValue->arrayValue->vector = new ValuesVector;
		traceKeyValue->arrayValue->vector->start = traceKeyValue->arrayValue->vector;
	}
	traceKeyValue->arrayValue->vector->root = tempArrayOfString->root;
	traceKeyValue->arrayValue->vector->child = tempArrayOfString;
	traceKeyValue->arrayValue->vector->parent = traceKeyValue->arrayValue;
	tempArrayOfString->parent = traceKeyValue->arrayValue->vector;

	traceKeyValue->arrayValue = tempArrayOfString;

	currentArrayOfString = traceKeyValue->arrayValue;
	return traceKeyValue;
}

struct ArrayOfString* gotoParentArray(struct KeyValue* traceKeyValue) {
	if (traceKeyValue == NULL) {
		return NULL;
	}
	if (traceKeyValue->arrayValue != NULL) {
		if (traceKeyValue->arrayValue->parent != NULL) {
			if (traceKeyValue->arrayValue->parent->parent != NULL) {
				traceKeyValue->arrayValue = traceKeyValue->arrayValue->parent->parent;
				currentArrayOfString = traceKeyValue->arrayValue;
			}
		}
	}
	return traceKeyValue->arrayValue;
}

int popKeyValueTrail() {
	if (currentKeyValueTrail->prev == NULL) {
		if (currentKeyValueTrail != NULL) {
			delete currentKeyValueTrail;
			currentKeyValue = NULL;
			currentKeyValueTrail = NULL;
		}
		return 1;
	}
	currentKeyValueTrail = currentKeyValueTrail->prev;
	delete currentKeyValueTrail->next;
	currentKeyValueTrail->next = NULL;
	currentKeyValue = currentKeyValueTrail->keyValue;
	while (currentKeyValue->next != NULL) {
		currentKeyValue = currentKeyValue->next;
	}
	return 1;
}

struct KeyValueTrail* newKeyValueTrail(struct KeyValueTrail* traceKeyValueTrail) {
	if (currentKeyValueTrail == NULL) {
		//EM_ASM({console.log("newkvtrail 401.1");});
		traceKeyValueTrail = new KeyValueTrail;
		traceKeyValueTrail->start = traceKeyValueTrail;
		traceKeyValueTrail->next = NULL;
		traceKeyValueTrail->prev = NULL;
		
	} else {
		//EM_ASM({console.log("newkvtrail 402.1");});
		struct KeyValueTrail* tempKeyValueTrail;
		tempKeyValueTrail = new KeyValueTrail;
		traceKeyValueTrail->next = tempKeyValueTrail;
		tempKeyValueTrail->prev = traceKeyValueTrail;
		tempKeyValueTrail->start = traceKeyValueTrail->start;
		traceKeyValueTrail = tempKeyValueTrail;
		
	}
	currentKeyValueTrail = traceKeyValueTrail;
	return traceKeyValueTrail;
}

int deleteArrayValue(struct ArrayOfString* passedArrayValue);

int deleteArrayValuesVector(struct ValuesVector* passedValuesVector) {
	//EM_ASM({console.log("deleteArrayValues 1101");});
	//struct ValuesVector* tempValuesVector;
	passedValuesVector = passedValuesVector->start;

	while (passedValuesVector != NULL && passedValuesVector->next != NULL) {
		if (passedValuesVector->child != NULL) {
			deleteArrayValue(passedValuesVector->child);
		}
		
		//tempValuesVector = passedValuesVector;
		
		passedValuesVector = passedValuesVector->next;
		
		//delete tempValuesVector;
		delete passedValuesVector->prev;
		
	}
	//EM_ASM({console.log("deleteArrayValues 1102");});


	if (passedValuesVector != NULL) {
		delete passedValuesVector;
	}
	return 1;
}

int deleteArrayValue(struct ArrayOfString* passedArrayValue) {

	if (passedArrayValue != NULL) {
		if (passedArrayValue->vector != NULL) {	
			deleteArrayValuesVector(passedArrayValue->vector->start);
		}
		delete passedArrayValue;
	}

	
	/*
struct ArrayOfString* tempArrayValue;
	if (passedArrayValue == NULL) {
		
		return 0;
	}
	//EM_ASM({console.log("pre deleteArrayValues 1104");});
	while (passedArrayValue != NULL && passedArrayValue->child != NULL) {
		
		tempArrayValue = passedArrayValue;
	

		
		//EM_ASM_({console.log("deleteArrayValues 1105 " + $0 + " : " + $1);}, passedArrayValue, passedArrayValue->child);
		passedArrayValue = passedArrayValue->child;
		//EM_ASM_({console.log("deleteArrayValues 1105.1 " + $0 + " : " + $1);}, passedArrayValue, passedArrayValue->child);
		
		delete tempArrayValue;
		//EM_ASM_({console.log("deleteArrayValues 1106 " + $0 + " : " + $1);}, passedArrayValue, passedArrayValue->child);
	}
	//EM_ASM({console.log("pre deleteArrayValues 1105");});
		
		if (passedArrayValue->vector != NULL) {
			deleteArrayValuesVector(passedArrayValue->vector->start);
		}
		delete passedArrayValue;
	}
	*/
	
	return 1;
}

struct KeyValueTrail* deleteKeyValues(struct KeyValueTrail* passedKeyValueTrail) {
	//EM_ASM({console.log("deleting key values 801");});
	char todisplay;
	char valdisplay;

	
	if (passedKeyValueTrail == NULL || passedKeyValueTrail->keyValue == NULL) {
		return 0;
	}
	struct KeyValue* tempKeyValue;
	struct KeyValue* temptempKeyValue;
	tempKeyValue = passedKeyValueTrail->keyValue;
	tempKeyValue = tempKeyValue->start;
	
	int counter = 0;
	//EM_ASM({console.log("deleting key values 802");});
	while (tempKeyValue != NULL && tempKeyValue->next != NULL) {
		
		if (strlen(tempKeyValue->key) > 0) {
			todisplay = tempKeyValue->key[0];
		} else {
			todisplay = ' ';
		}
		
		if (strlen(tempKeyValue->value) > 0) {
			valdisplay = tempKeyValue->value[0];
		} else {
			valdisplay = ' ';
		}
		
		counter++;
		
		temptempKeyValue = tempKeyValue;
		tempKeyValue = tempKeyValue->next;
		
		//EM_ASM_({console.log("deleting key values 802.2 " + $0 + " : " + $1);}, temptempKeyValue, tempKeyValue);
		if (temptempKeyValue->arrayValue != NULL) {
			if (temptempKeyValue->arrayValue->root != NULL) {
				deleteArrayValue(temptempKeyValue->arrayValue->root);
				temptempKeyValue->arrayValue = NULL;
			}
		}
		//delete temptempKeyValue->arrayValue;
		delete temptempKeyValue;
	}
	//EM_ASM({console.log("deleting key values 803");});
	
	if (tempKeyValue != NULL) {
		//EM_ASM({console.log("deleting key values 803.1");});
		if (strlen(tempKeyValue->key) > 0) {
			todisplay = tempKeyValue->key[0];
		} else {
			todisplay = ' ';
		}
		//EM_ASM({console.log("deleting key values 803.2");});
		if (tempKeyValue->arrayValue != NULL && tempKeyValue->arrayValue->root != NULL) {
			//EM_ASM({console.log("deleting key values 803.2.1");});
			deleteArrayValue(tempKeyValue->arrayValue->root);
		}
		
		//EM_ASM_({console.log("deleting key values 803.3 " + $0);}, tempKeyValue);
		//delete tempKeyValue->arrayValue;
		delete tempKeyValue;
	}
	
	//EM_ASM({console.log("deleting key values 804");});
	if (passedKeyValueTrail->prev != NULL) {
		if (passedKeyValueTrail->next != NULL) {
			passedKeyValueTrail->next->prev = passedKeyValueTrail->prev;
			passedKeyValueTrail->prev->next = passedKeyValueTrail->next;
		} else {
			//passedKeyValueTrail->next->prev = NULL;
		}
	}
	
	//EM_ASM({console.log("deleting key values 805");});
	if (passedKeyValueTrail->next != NULL) {
		if (passedKeyValueTrail->prev != NULL) {
			passedKeyValueTrail->prev->next = passedKeyValueTrail->next;
			passedKeyValueTrail->next->prev = passedKeyValueTrail->prev;
		} else {
			//passedKeyValueTrail->prev->next = NULL;
		}
	}
	struct KeyValueTrail* temptempKeyValueTrail;
	temptempKeyValueTrail = passedKeyValueTrail->prev;
	delete passedKeyValueTrail;
	return temptempKeyValueTrail;
}

int removeKeyValueTrail() { // to be called from within associateKeyValue()
	struct KeyValueTrail* tempKeyValueTrail;
	tempKeyValueTrail = currentKeyValueTrail;
	if (currentKeyValueTrail->prev != NULL) {
		currentKeyValueTrail = currentKeyValueTrail->prev;
		currentKeyValue = currentKeyValueTrail->keyValue;
		//currentKeyValue->next = NULL;
		currentArrayOfString = currentKeyValueTrail->keyValue->arrayValue;
		currentKeyValueTrail->next = NULL;

		//deleteKeyValues(tempKeyValueTrail);
		delete tempKeyValueTrail;
	}

	return 1;
}

int removeKeyValue() {
	struct KeyValue* tempKeyValue;
	currentKeyValue->prev->next = currentKeyValue->next;
	if (currentKeyValue->next != NULL) {
		currentKeyValue->next->prev = currentKeyValue->prev;
	}
	tempKeyValue = currentKeyValue->prev;
	delete currentKeyValue;
	currentKeyValue = tempKeyValue;

	return 1;
}

int pushValuesVector(struct ArrayOfString* traceArrayOfString, string tempString) {
	struct ValuesVector* tempVector;
	struct ValuesVector* traceVector;

	if (traceArrayOfString->vector != NULL) {
		traceVector = new ValuesVector;
		if (tempString.length() > 20) {
			strcpy(traceVector->value, tempString.substr(0,20).c_str());
		} else {
			strcpy(traceVector->value, tempString.c_str());
		}
		traceVector->start = traceArrayOfString->vector->start;
		traceArrayOfString->vector->next = traceVector;
		traceVector->prev = traceArrayOfString->vector;

		traceArrayOfString->vector = traceVector;
		//EM_ASM_({console.log("pushValuesVector 1.0 " + String.fromCharCode($0));}, traceArrayOfString->vector->value[0]);	
	} else {
		traceArrayOfString->vector = new ValuesVector;
		traceArrayOfString->vector->start = traceArrayOfString->vector;
	
		if (tempString.length() > 20) {
			strcpy(traceArrayOfString->vector->value, tempString.substr(0,20).c_str());
		} else {
			strcpy(traceArrayOfString->vector->value, tempString.c_str());
		}
	}
		//EM_ASM_({console.log("pushValuesVector 2.0 " + String.fromCharCode($0));}, traceArrayOfString->vector->value[0]);	
	return 1;
}

string popValuesVector(struct ValuesVector* traceVector) {
	//EM_ASM({console.log("adding array vector ");});	
	if (traceVector != NULL) {
		struct ValuesVector* tempVector;
		tempVector = traceVector;
		string tempString = tempVector->value;
		if (traceVector->prev != NULL) {
			traceVector = traceVector->prev;
			traceVector->next = NULL;
			return tempString;
		} else {
			return tempString;
		}
		delete tempVector;
	}
	return NULL;
}

struct KeyValue* addKeyValue(struct KeyValue* traceKeyValue, string key, string value, bool isArray) {
	bool exhausted = false;
	struct KeyValue* keyNode = NULL;
	struct KeyValue* endNode = NULL;
	struct KeyValue* createdKeyValue = NULL;

	//EM_ASM({console.log("adding key value 300.1");});	
	if (traceKeyValue != NULL) {
		//EM_ASM({console.log("adding key value 301.1");});	
		struct KeyValue* tempKeyValue = traceKeyValue;
		//EM_ASM({console.log("adding key value 301.2");});	
		if (keyFound(traceKeyValue, key)) {
			
			keyNode = traceKeyValue;
		} else {
			//EM_ASM({console.log("adding key value 301.3");});	
			
			while (! exhausted) {
				
				if (keyFound(tempKeyValue, key)) {
					keyNode = tempKeyValue;
				}
				
				if (tempKeyValue->next == NULL) {
					endNode = tempKeyValue;
					exhausted = true;
				} else {
					tempKeyValue = tempKeyValue->next;
				}
			}
		}
		
	} else {
		//EM_ASM({console.log("adding key value 302.1");});	
		
		createdKeyValue = new KeyValue;
		
		createdKeyValue->start = createdKeyValue;
		createdKeyValue->prev = NULL;
		createdKeyValue->next = NULL;
		keyNode = createdKeyValue;
		//keyNode->arrayValue = new ArrayOfString;
		//addChildArray(keyNode);
		/*
		if (keyNode->arrayValue == NULL) {
			keyNode->arrayValue = new ArrayOfString;
			keyNode->arrayValue->root = keyNode->arrayValue;
		}
		*/
		
		if (key.length() > 20) {
			strcpy(keyNode->key, key.substr(0,20).c_str());
		} else {
			strcpy(keyNode->key, key.c_str());
		}
		
	}
	//EM_ASM({console.log("adding key value 303.1");});	
	
	if (keyNode == NULL) {
		//EM_ASM({console.log("adding key value 303.2");});	
		keyNode = new KeyValue;
		
		//EM_ASM({console.log("adding key value 303.3");});	
		if (endNode != NULL) {
			endNode->next = keyNode;
			//EM_ASM({console.log("adding key value 303.4");});	
			keyNode->prev = endNode;
			//EM_ASM({console.log("adding key value 303.5");});	
			keyNode->start = endNode->start;
		} else {
			//EM_ASM({console.log("adding key value 303.6");});	
			keyNode->start = keyNode;
		}

		//EM_ASM({console.log("adding key value 303.7");});	
		/*
		keyNode->arrayValue = new ArrayOfString;
		if (endNode != NULL) {
			//EM_ASM({console.log("adding key value 303.7.1");});	
			keyNode->arrayValue->root = endNode->arrayValue->root;
		} else {
			//EM_ASM({console.log("adding key value 303.7.2");});	
			keyNode->arrayValue->root = keyNode->arrayValue;
		}
		*/

		if (traceKeyValue != NULL) {
			//EM_ASM({console.log("adding key value 303.7.3");});	
			keyNode->start = traceKeyValue->start;
		} else {
			//EM_ASM({console.log("adding key value 303.7.4");});	
			keyNode->start = keyNode;
		}
		//EM_ASM({console.log("adding key value 303.7.5");});	
		
		//addChildArray(keyNode);
		//keyNode->arrayValue = new ArrayOfString;
		//EM_ASM({console.log("adding key value 303.8");});	
		if (key.length() > 20) {
			strcpy(keyNode->key, key.substr(0,20).c_str());
		} else {
			strcpy(keyNode->key, key.c_str());
		}
		
	}
	if (isArray) {
		/*
			struct ArrayOfString* tempArrayOfString;
			tempArrayOfString = new ArrayOfString;
			currentArrayOfString = tempArrayOfString;
			keyNode->arrayValue->child = tempArrayOfString;
			tempArrayOfString->parent = keyNode->arrayValue;
			keyNode->arrayValue = tempArrayOfString;
		*/
		//keyNode->arrayValue->value.push_back(value);
		if (keyNode->arrayValue == NULL) {
			addChildArray(keyNode);
			//keyNode->arrayValue->root = keyNode->arrayValue;
		}
		pushValuesVector(keyNode->arrayValue, value);
		
	} else {
		if (key.length() > 20) {
			strcpy(keyNode->value, value.substr(0,20).c_str());
		} else {
			strcpy(keyNode->value, value.c_str());
		}
		
	}
	if (!value.empty()) {
		
	}
	//traceKeyValue = keyNode;
	//EM_ASM({console.log("adding key value 320.1");});	
	return keyNode;
}

int pushVertex(struct ArrayOfVertex* passedVertex, float vertex[4]) {
	struct ArrayOfVertex* tempAOV;
	tempAOV = new ArrayOfVertex;
	/*if (passedVertex == NULL) {
		passedVertex = tempAOV;
		passedVertex->start = tempAOV;
		passedVertex->prev = NULL;
		passedVertex->next = NULL;
	} else {*/
		bool exhausted = false;
		while (! exhausted) {
			if (passedVertex->next == NULL) {
				exhausted = true;
			} else {
				passedVertex = passedVertex->next;
			}
		}
		tempAOV->prev = passedVertex;
		passedVertex->next = tempAOV;
		tempAOV->start = passedVertex->start;
		passedVertex = tempAOV;
	//}

	if (passedVertex->vertex == NULL) {
		passedVertex->vertex = new Vertex;
	}

	passedVertex->vertex->position[0] = vertex[0];
	passedVertex->vertex->position[1] = vertex[1];
	passedVertex->vertex->position[2] = vertex[2];
	passedVertex->vertex->position[3] = vertex[3];

	return 1;
}

//////////// type converters


