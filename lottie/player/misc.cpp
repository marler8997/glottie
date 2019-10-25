
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
		if (!tempKeyValue->key.empty()) {
			if (tempKeyValue->key == key) {
				EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> found key" + String.fromCharCode($0));}, key.at(0));
				return true;
			}
		}
	}
	return false;
}

struct KeyValue* addChildArray(struct KeyValue* traceKeyValue) {
	struct ArrayOfString* tempArrayOfString;
	tempArrayOfString = new ArrayOfString;
	if (traceKeyValue->arrayValue == NULL) {
		traceKeyValue = new KeyValue;
		traceKeyValue->arrayValue = tempArrayOfString;
		traceKeyValue->arrayValue->root = tempArrayOfString;
		return traceKeyValue;
	}
	tempArrayOfString->root = traceKeyValue->arrayValue->root;
	currentArrayOfString = tempArrayOfString;
	tempArrayOfString->parent = traceKeyValue->arrayValue;
	traceKeyValue->arrayValue->child = tempArrayOfString;
	traceKeyValue->arrayValue = tempArrayOfString;
	return traceKeyValue;
}

int gotoParentArray(struct KeyValue* traceKeyValue) {
	if (traceKeyValue->arrayValue != NULL) {
		if (traceKeyValue->arrayValue->parent != NULL) {
			traceKeyValue->arrayValue = traceKeyValue->arrayValue->parent;
		}
	}
	return 1;
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

int newKeyValueTrail() {
	if (currentKeyValueTrail == NULL) {
		currentKeyValueTrail = new KeyValueTrail;
		currentKeyValueTrail->start = currentKeyValueTrail;
		currentKeyValueTrail->next = NULL;
		currentKeyValueTrail->prev = NULL;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> key trail created");});
		
	} else {
		struct KeyValueTrail* tempKeyValueTrail;
		tempKeyValueTrail = new KeyValueTrail;
		currentKeyValueTrail->next = tempKeyValueTrail;
		tempKeyValueTrail->prev = currentKeyValueTrail;
		tempKeyValueTrail->start = currentKeyValueTrail->start;
		currentKeyValueTrail = tempKeyValueTrail;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> key trail extended");});
		
	}
	return 1;
}

int deleteArrayValuesVector(struct ValuesVector* passedValuesVector) {
	struct ValuesVector* tempValuesVector;
	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting vector 0.1 ");});
	while (passedValuesVector != NULL && passedValuesVector->next != NULL) {
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting vector 0.2 ");});
		tempValuesVector = passedValuesVector;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting vector 0.3 ");});
		passedValuesVector = passedValuesVector->next;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting vector 0.4 ");});
		delete tempValuesVector;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting vector 0.5 ");});
	}
	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting vector 0.6 ");});
	if (passedValuesVector != NULL) {
		delete passedValuesVector;
	}
	return 1;
}

int deleteArrayValue(struct ArrayOfString* passedArrayValue) {
	/*EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting arrayofstring 1.0");});
	if (passedArrayValue == NULL || passedArrayValue->vector->start == NULL) {
		return 1;
	}
	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting arrayofstring 1.1");});
	if (passedArrayValue->child != NULL) {
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting arrayofstring 1.2");});
		deleteArrayValue(passedArrayValue->child);
		if (passedArrayValue->vector != NULL) {
			deleteArrayValuesVector(passedArrayValue->vector->start);
		}
		delete passedArrayValue;
	} else {
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting arrayofstring 1.3");});
		if (passedArrayValue->vector != NULL) {
			deleteArrayValuesVector(passedArrayValue->vector->start);
		}
		delete passedArrayValue;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleted arrayofstring");});
	}
	*/
	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting array_value 0.1 ");});
	struct ArrayOfString* tempArrayValue;
	if (passedArrayValue == NULL) {
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting array_value 0.3 ");});
		return 0;
	}
	while (passedArrayValue != NULL && passedArrayValue->child != NULL) {
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting array_value 0.4 ");});
		tempArrayValue = passedArrayValue;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting array_value 0.5 ");});
		deleteArrayValuesVector(passedArrayValue->vector->start);
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting array_value 0.6 ");});
		passedArrayValue = passedArrayValue->child;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting array_value 0.7 ");});
		delete tempArrayValue;
	}
	if (passedArrayValue != NULL) {
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting array_value 0.8 ");});
		if (passedArrayValue->vector != NULL) {
			deleteArrayValuesVector(passedArrayValue->vector->start);
		}
		delete passedArrayValue;
	}
	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting array_value 0.2 ");});
	return 1;
}

int deleteKeyValues(struct KeyValueTrail* passedKeyValueTrail) {
	char todisplay;
	char valdisplay;

	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting kv");});
	if (passedKeyValueTrail == NULL) {
		return 0;
	}
	struct KeyValue* tempKeyValue;
	struct KeyValue* temptempKeyValue;
	tempKeyValue = passedKeyValueTrail->keyValue;
	tempKeyValue = tempKeyValue->start;
	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting kv 0.1");});
	int counter = 0;
	while (tempKeyValue->next != NULL) {
		if (!tempKeyValue->key.empty()) {
			todisplay = tempKeyValue->key.at(0);
		} else {
			todisplay = ' ';
		}
		if (!tempKeyValue->value.empty()) {
			valdisplay = tempKeyValue->value.at(0);
		} else {
			valdisplay = ' ';
		}
		counter++;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting kv 0.0.1 " + $0);}, counter);
		temptempKeyValue = tempKeyValue;
		tempKeyValue = tempKeyValue->next;
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting kv 0.0.2 " + String.fromCharCode($0));}, valdisplay);
		if (temptempKeyValue->arrayValue != NULL && temptempKeyValue->arrayValue->root != NULL) {
			deleteArrayValue(temptempKeyValue->arrayValue->root);
		}
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting kv 0.0.3 " + String.fromCharCode($0));}, todisplay);
		delete temptempKeyValue;
	}
	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting kv 0.2");});
	if (tempKeyValue != NULL) {
		if (!tempKeyValue->key.empty()) {
			todisplay = tempKeyValue->key.at(0);
		} else {
			todisplay = ' ';
		}
		if (temptempKeyValue->arrayValue != NULL) {
			deleteArrayValue(tempKeyValue->arrayValue->root);
		}
		EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting kv 0.0.3 " + String.fromCharCode($0));}, todisplay);
		delete tempKeyValue;
	}
	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting kv 0.3");});
	if (passedKeyValueTrail->prev != NULL) {
		if (passedKeyValueTrail->next != NULL) {
			passedKeyValueTrail->next->prev = passedKeyValueTrail->prev;
		} else {
			passedKeyValueTrail->next->prev = NULL;
		}
	}
	EM_ASM({console.log(">>>>>>>>>>>>>>>>>>>> deleting kv 0.4");});
	if (passedKeyValueTrail->next != NULL) {
		if (passedKeyValueTrail->prev != NULL) {
			passedKeyValueTrail->prev->next = passedKeyValueTrail->next;
		} else {
			passedKeyValueTrail->prev->next = NULL;
		}
	}
		
	delete passedKeyValueTrail;
	return 1;
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
	struct ValuesVector* traceVector = traceArrayOfString->vector;
	EM_ASM({console.log("push vector 450.1");});
	if (traceVector == NULL) {
		EM_ASM({console.log("push vector 450.2");});
		traceVector = new ValuesVector;
		traceVector->start = traceVector;
		traceVector->next = NULL;
		traceVector->prev = NULL;
		traceVector->value.reserve(30);
		if (tempString.length() > 30) {
			tempVector->value = tempString.substr(0,30);
		} else {
			tempVector->value = tempString;
		}
		traceArrayOfString->vector = traceVector;
		EM_ASM({console.log("push vector 450.3");});
	} else {
		EM_ASM({console.log("push vector 450.4");});
		tempVector = new ValuesVector;
		EM_ASM({console.log("push vector 450.4.1");});
		tempVector->value.reserve(30);
		//tempVector->value = tempString;
		EM_ASM({console.log("push vector 450.4.2");});
		if (tempString.length() > 30) {
			tempVector->value = tempString.substr(0,30);
		} else {
			tempVector->value = tempString;
		}
		EM_ASM({console.log("push vector 450.4.3");});
		traceVector->next = tempVector;
		EM_ASM({console.log("push vector 450.4.4");});
		tempVector->prev = traceVector;
		EM_ASM({console.log("push vector 450.4.5");});
		tempVector->start = traceVector->start;
		EM_ASM({console.log("push vector 450.4.6");});
		traceVector = tempVector;
		EM_ASM({console.log("push vector 450.4.7");});
		traceArrayOfString->vector = traceVector;
		EM_ASM({console.log("push vector 450.5");});
	}
	return 1;
}

string popValuesVector(struct ValuesVector* traceVector) {
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
	EM_ASM({console.log("adding keyvalue 200.1");});
	if (traceKeyValue != NULL) {
		struct KeyValue* tempKeyValue = traceKeyValue;
		if (keyFound(traceKeyValue, key)) {
			EM_ASM({console.log("adding keyvalue 200.1.1");});
			keyNode = traceKeyValue;
		} else {
			EM_ASM({console.log("adding keyvalue 200.1.2");});
			while (! exhausted) {
				EM_ASM({console.log("adding keyvalue 200.1.2.1.1");});
				if (keyFound(tempKeyValue, key)) {
					keyNode = tempKeyValue;
				}
				EM_ASM({console.log("adding keyvalue 200.1.2.1");});
				if (tempKeyValue->next == NULL) {
					endNode = tempKeyValue;
					exhausted = true;
				} else {
					tempKeyValue = tempKeyValue->next;
				}
			}
		}
		EM_ASM({console.log("adding keyvalue 200.1.3");});
	} else {
		EM_ASM({console.log("adding keyvalue 200.1.4");});
		createdKeyValue = new KeyValue;
		EM_ASM({console.log("adding keyvalue 200.1.5");});
		createdKeyValue->start = traceKeyValue->start;
		createdKeyValue->prev = NULL;
		createdKeyValue->next = NULL;
		keyNode = createdKeyValue;
		//keyNode->arrayValue = new ArrayOfString;
		//addChildArray(keyNode);
		keyNode->key = key;
		EM_ASM_({console.log(">>>>>>>>>>>>>>>>>>>> first key added " + String.fromCharCode($0));}, keyNode->key.at(0));
	}
	EM_ASM({console.log("adding keyvalue 200.2");});
	if (keyNode == NULL) {
		keyNode = new KeyValue;
		EM_ASM({console.log("adding keyvalue 200.2.1");});
		endNode->next = keyNode;
		EM_ASM({console.log("adding keyvalue 200.2.2");});
		keyNode->prev = endNode;
		EM_ASM({console.log("adding keyvalue 200.2.3");});
		if (traceKeyValue != NULL) {
			EM_ASM({console.log("adding keyvalue 200.2.3.1");});
			keyNode->start = traceKeyValue->start;
		} else {
			EM_ASM({console.log("adding keyvalue 200.2.3.2");});
			keyNode->start = keyNode;
		}
		EM_ASM({console.log("adding keyvalue 200.2.4");});
		//addChildArray(keyNode);
		//keyNode->arrayValue = new ArrayOfString;
		EM_ASM({console.log("adding keyvalue 200.2.5");});
		keyNode->key = key;
		EM_ASM_({console.log(">>>>>>>>>>>>>>>>>>>> new key added " + String.fromCharCode($0));}, keyNode->key.at(0));
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
		pushValuesVector(keyNode->arrayValue, value);
		EM_ASM({console.log("adding keyvalue 200.5");});
	} else {
		EM_ASM({console.log("adding keyvalue 200.3");});
		keyNode->value = value;
		EM_ASM({console.log("adding keyvalue 200.4");});
	}
	if (!value.empty()) {
		EM_ASM_({console.log(">>>>>>>>>>>>>>>>>>>> with value " + String.fromCharCode($0));}, value.at(0));
	}
	//traceKeyValue = keyNode;
	return keyNode;
}

int pushVertex(struct ArrayOfVertex* passedVertex, float vertex[4]) {
	struct ArrayOfVertex* tempAOV;
	tempAOV = new ArrayOfVertex;
	if (passedVertex == NULL) {
		passedVertex = tempAOV;
		passedVertex->start = tempAOV;
		passedVertex->prev = NULL;
		passedVertex->next = NULL;
	} else {
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
	}

	passedVertex->vertex->position[0] = vertex[0];
	passedVertex->vertex->position[1] = vertex[1];
	passedVertex->vertex->position[2] = vertex[2];
	passedVertex->vertex->position[3] = vertex[3];

	return 1;
}

//////////// type converters


