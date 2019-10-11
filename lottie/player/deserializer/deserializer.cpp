
#include "properties.h"
#include "shapes.h"
#include "layers.h"

/*
string jsonString = "{'v':'5.5.7','fr':60,'ip':0,'op':480,'w':110,'h':110,'nm':'','ddd':0,'assets':[{'id':'comp_0','layers':[{'ddd':0,'ind':2,'ty':4,'nm':'2','td':1,'sr':1,'ks':{'o':{'a':0,'k':100,'ix':11},'r':{'a':0,'k':0,'ix':10},'p':{'a':0,'k':[375,667,0],'ix':2},'a':{'a':0,'k':[375,210,0],'ix':1},'s':{'a':0,'k':[100,100,100],'ix':6}},'ao':0,'shapes':[{'ty':'gr','it':[{'ind':0,'ty':'sh','ix':1,'ks':{'a':0,'k':{'i':[[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]],'o':[[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]],'v':[[-10.589,-56],[33.176,-56],[4.47,-16.941],[29.882,-16.941],[-30.824,56],[-10.589,4.639],[-33.177,4.639]],'c':true},'ix':2},'nm':' 1','mn':'ADBE Vector Shape - Group','hd':false},{'ty':'fl','c':{'a':0,'k':[0,0,0,1],'ix':4},'o':{'a':0,'k':100,'ix':5},'r':1,'bm':0,'nm':' 1','mn':'ADBE Vector Graphic - Fill','hd':false},{'ty':'tr','p':{'a':0,'k':[390.668,212.29],'ix':2},'a':{'a':0,'k':[0,0],'ix':1},'s':{'a':0,'k':[100,100],'ix':3},'r':{'a':0,'k':0,'ix':6},'o':{'a':0,'k':100,'ix':7},'sk':{'a':0,'k':0,'ix':4},'sa':{'a':0,'k':0,'ix':5},'nm':''}],'nm':' 1','np':2,'cix':2,'bm':0,'ix':1,'mn':'ADBE Vector Group','hd':false}],'ip':0,'op':478,'st':0,'bm':0},{'ddd':0,'ind':3,'ty':0,'nm':' 1  1','tt':1,'refId':'comp_1','sr':1,'ks':{'o':{'a':0,'k':100,'ix':11},'r':{'a':0,'k':0,'ix':10},'p':{'a':1,'k':[{'i':{'x':0.833,'y':0.833},'o':{'x':0.167,'y':0.167},'t':0,'s':[875,737,0],'to':[-180.333,0,0],'ti':[180.333,0,0]},{'t':478,'s':[-207,737,0]}],'ix':2},'a':{'a':0,'k':[750,667,0],'ix':1},'s':{'a':0,'k':[100,100,100],'ix':6}},'ao':0,'w':1500,'h':1334,'ip':0,'op':480,'st':0,'bm':0}]},{'id':'comp_1','layers':[{'ddd':0,'ind':1,'ty':0,'nm':' 1','refId':'comp_2','sr':1,'ks':{'o':{'a':0,'k':100,'ix':11},'r':{'a':0,'k':0,'ix':10},'p':{'a':1,'k':[{'i':{'x':0.667,'y':1},'o':{'x':0.333,'y':0},'t':0,'s':[751,628.5,0],'to':[2.5,-25.833,0],'ti':[-2.5,25.833,0]},{'i':{'x':0.667,'y':0.667},'o':{'x':0.333,'y':0.333},'t':120,'s':[766,473.5,0],'to':[0,0,0],'ti':[0,0,0]},{'i':{'x':0.667,'y':1},'o':{'x':0.333,'y':0},'t':240,'s':[766,473.5,0],'to':[-1.5,8,0],'ti':[1,-1.667,0]},{'i':{'x':0.667,'y':1},'o':{'x':0.333,'y':0},'t':300,'s':[757,521.5,0],'to':[-1,1.667,0],'ti':[-0.5,6.333,0]},{'i':{'x':0.667,'y':0.667},'o':{'x':0.333,'y':0.333},'t':360,'s':[760,483.5,0],'to':[0,0,0],'ti':[0,0,0]},{'i':{'x':0.667,'y':1},'o':{'x':0.333,'y':0},'t':420,'s':[760,483.5,0],'to':[-4.5,25.667,0],'ti':[4.5,-25.667,0]},{'t':476,'s':[733,637.5,0]}],'ix':2},'a':{'a':0,'k':[750,667,0],'ix':1},'s':{'a':0,'k':[100,100,100],'ix':6}},'ao':0,'w':1500,'h':1334,'ip':0,'op':480,'st':0,'bm':0}]},{'id':'comp_2','layers':[{'ddd':0,'ind':1,'ty':4,'nm':' 2','sr':1,'ks':{'o':{'a':0,'k':70,'ix':11},'r':{'a':0,'k':0,'ix':10},'p':{'a':0,'k':[753,660,0],'ix':2},'a':{'a':0,'k':[0,0,0],'ix':1},'s':{'a':0,'k':[100,100,100],'ix':6}},'ao':0,'shapes':[{'ty':'gr','it':[{'ind':0,'ty':'sh','ix':1,'ks':{'a':0,'k':{'i':[[57,24],[16,13],[54,-4],[50,59],[65,9],[45,45],[74,47],[19,-23],[63,25],[0,0],[0,0],[0,0],[0,0],[0,0],[25,58],[29,-8]],'o':[[-57,-24],[-16,-13],[-54,4],[-50,-59],[-65,-9],[-45,-45],[-74,-47],[-19,23],[-63,-25],[0,0],[0,0],[0,0],[0,0],[0,0],[-25,-58],[-29,8]],'v':[[425,56],[339,111],[240,83],[155,127],[-2,73],[-84,109],[-192,126],[-358,123],[-462,117],[-574,129],[-559,264],[164,280],[524,263],[569,232],[572,103],[492,100]],'c':true},'ix':2},'nm':' 1','mn':'ADBE Vector Shape - Group','hd':false},{'ty':'fl','c':{'a':0,'k':[0.03529400171,0.705881993911,0.580391977348,1],'ix':4},'o':{'a':0,'k':100,'ix':5},'r':1,'bm':0,'nm':' 1','mn':'ADBE Vector Graphic - Fill','hd':false},{'ty':'tr','p':{'a':0,'k':[0,0],'ix':2},'a':{'a':0,'k':[0,0],'ix':1},'s':{'a':0,'k':[100,100],'ix':3},'r':{'a':0,'k':0,'ix':6},'o':{'a':0,'k':100,'ix':7},'sk':{'a':0,'k':0,'ix':4},'sa':{'a':0,'k':0,'ix':5},'nm':''}],'nm':' 1','np':3,'cix':2,'bm':0,'ix':1,'mn':'ADBE Vector Group','hd':false}],'ip':0,'op':480,'st':0,'bm':0},{'ddd':0,'ind':2,'ty':4,'nm':' 1','sr':1,'ks':{'o':{'a':0,'k':70,'ix':11},'r':{'a':0,'k':0,'ix':10},'p':{'a':0,'k':[816,631,0],'ix':2},'a':{'a':0,'k':[0,0,0],'ix':1},'s':{'a':0,'k':[100,100,100],'ix':6}},'ao':0,'shapes':[{'ty':'gr','it':[{'ind':0,'ty':'sh','ix':1,'ks':{'a':0,'k':{'i':[[112,50],[28,0],[62,0],[48,68],[48,-18],[18,48],[34,-24],[18,50],[10,-2],[76,96],[0,0],[0,0],[0,0],[32,32],[52,-30]],'o':[[-60.295,-26.917],[-28,0],[-62,0],[-48,-68],[-48,18],[-18,-48],[-34,24],[-18,-50],[-10,2],[-76,-96],[0,0],[0,0],[0,0],[-32,-32],[-52,30]],'v':[[265,87],[187,125],[93,105],[7,93],[-109,145],[-191,137],[-315,129],[-365,119],[-421,101],[-483,119],[-601,155],[-603,239],[633,235],[617,115],[461,109]],'c':true},'ix':2},'nm':' 1','mn':'ADBE Vector Shape - Group','hd':false},{'ty':'fl','c':{'a':0,'k':[0.03529400171,0.705881993911,0.580391977348,1],'ix':4},'o':{'a':0,'k':100,'ix':5},'r':1,'bm':0,'nm':' 1','mn':'ADBE Vector Graphic - Fill','hd':false},{'ty':'tr','p':{'a':0,'k':[-2,30],'ix':2},'a':{'a':0,'k':[0,0],'ix':1},'s':{'a':0,'k':[100,100],'ix':3},'r':{'a':0,'k':0,'ix':6},'o':{'a':0,'k':100,'ix':7},'sk':{'a':0,'k':0,'ix':4},'sa':{'a':0,'k':0,'ix':5},'nm':''}],'nm':' 1','np':3,'cix':2,'bm':0,'ix':1,'mn':'ADBE Vector Group','hd':false}],'ip':0,'op':480,'st':0,'bm':0}]}],'layers':[{'ddd':0,'ind':1,'ty':0,'nm':' ','refId':'comp_0','sr':1,'ks':{'o':{'a':0,'k':100,'ix':11},'r':{'a':0,'k':0,'ix':10},'p':{'a':0,'k':[55,55,0],'ix':2},'a':{'a':0,'k':[375,667,0],'ix':1},'s':{'a':0,'k':[100,100,100],'ix':6}},'ao':0,'w':750,'h':1334,'ip':0,'op':480,'st':0,'bm':0}],'markers':[]}";
*/


string jsonString = "{'v':'5.5.8','fr':24,'ip':0,'op':63,'w':900,'h':900,'nm':'Comp 1','ddd':1,'assets':[],'layers':[{'ddd':1,'ind':1,'ty':4,'nm':'Shape Layer 4','parent':4,'sr':1,'ks':{'o':{'a':0,'k':100,'ix':11},'rx':{'a':0,'k':0,'ix':8},'ry':{'a':0,'k':270,'ix':9},'rz':{'a':0,'k':0,'ix':10},'or':{'a':0,'k':[0,0,0],'ix':7},'p':{'a':0,'k':[51,0,0],'ix':2},'a':{'a':0,'k':[51,0,0],'ix':1},'s':{'a':0,'k':[100,100,100],'ix':6}},'ao':0,'shapes':[{'ty':'gr','it':[{'ind':0,'ty':'sh','ix':1,'ks':{'a':0,'k':{'i':[[0,0],[0,0],[0,0]],'o':[[0,0],[0,0],[0,0]],'v':[[51.071,102.142],[-51.071,0],[51.071,-102.142]],'c':true},'ix':2},'nm':'Path 1','mn':'ADBE Vector Shape - Group','hd':false},{'ty':'fl','c':{'a':0,'k':[0.125490196078,0.639215686275,0.619607843137,1],'ix':4},'o':{'a':0,'k':100,'ix':5},'r':1,'bm':0,'nm':'Fill 1','mn':'ADBE Vector Graphic - Fill','hd':false},{'ty':'tr','p':{'a':0,'k':[0,0],'ix':2},'a':{'a':0,'k':[0,0],'ix':1},'s':{'a':0,'k':[100,100],'ix':3},'r':{'a':0,'k':0,'ix':6},'o':{'a':0,'k':100,'ix':7},'sk':{'a':0,'k':0,'ix':4},'sa':{'a':0,'k':0,'ix':5},'nm':'Transform'}],'nm':'Shape 1','np':3,'cix':2,'bm':0,'ix':1,'mn':'ADBE Vector Group','hd':false}],'ip':0,'op':658,'st':0,'bm':0},{'ddd':1,'ind':2,'ty':4,'nm':'Shape Layer 3','parent':4,'sr':1,'ks':{'o':{'a':0,'k':100,'ix':11},'rx':{'a':0,'k':0,'ix':8},'ry':{'a':0,'k':180,'ix':9},'rz':{'a':0,'k':0,'ix':10},'or':{'a':0,'k':[0,0,0],'ix':7},'p':{'a':0,'k':[51,0,0],'ix':2},'a':{'a':0,'k':[51,0,0],'ix':1},'s':{'a':0,'k':[100,100,100],'ix':6}},'ao':0,'shapes':[{'ty':'gr','it':[{'ind':0,'ty':'sh','ix':1,'ks':{'a':0,'k':{'i':[[0,0],[0,0],[0,0]],'o':[[0,0],[0,0],[0,0]],'v':[[51.071,102.142],[-51.071,0],[51.071,-102.142]],'c':true},'ix':2},'nm':'Path 1','mn':'ADBE Vector Shape - Group','hd':false},{'ty':'fl','c':{'a':0,'k':[0.882352941176,0.333333333333,0.329411764706,1],'ix':4},'o':{'a':0,'k':100,'ix':5},'r':1,'bm':0,'nm':'Fill 1','mn':'ADBE Vector Graphic - Fill','hd':false},{'ty':'tr','p':{'a':0,'k':[0,0],'ix':2},'a':{'a':0,'k':[0,0],'ix':1},'s':{'a':0,'k':[100,100],'ix':3},'r':{'a':0,'k':0,'ix':6},'o':{'a':0,'k':100,'ix':7},'sk':{'a':0,'k':0,'ix':4},'sa':{'a':0,'k':0,'ix':5},'nm':'Transform'}],'nm':'Shape 1','np':3,'cix':2,'bm':0,'ix':1,'mn':'ADBE Vector Group','hd':false}],'ip':0,'op':658,'st':0,'bm':0},{'ddd':1,'ind':3,'ty':4,'nm':'Shape Layer 2','parent':4,'sr':1,'ks':{'o':{'a':0,'k':100,'ix':11},'rx':{'a':0,'k':0,'ix':8},'ry':{'a':0,'k':90,'ix':9},'rz':{'a':0,'k':0,'ix':10},'or':{'a':0,'k':[0,0,0],'ix':7},'p':{'a':0,'k':[51,0,0],'ix':2},'a':{'a':0,'k':[51,0,0],'ix':1},'s':{'a':0,'k':[100,100,100],'ix':6}},'ao':0,'shapes':[{'ty':'gr','it':[{'ind':0,'ty':'sh','ix':1,'ks':{'a':0,'k':{'i':[[0,0],[0,0],[0,0]],'o':[[0,0],[0,0],[0,0]],'v':[[51.071,102.142],[-51.071,0],[51.071,-102.142]],'c':true},'ix':2},'nm':'Path 1','mn':'ADBE Vector Shape - Group','hd':false},{'ty':'fl','c':{'a':0,'k':[0.44099222819,0,1,1],'ix':4},'o':{'a':0,'k':100,'ix':5},'r':1,'bm':0,'nm':'Fill 1','mn':'ADBE Vector Graphic - Fill','hd':false},{'ty':'tr','p':{'a':0,'k':[0,0],'ix':2},'a':{'a':0,'k':[0,0],'ix':1},'s':{'a':0,'k':[100,100],'ix':3},'r':{'a':0,'k':0,'ix':6},'o':{'a':0,'k':100,'ix':7},'sk':{'a':0,'k':0,'ix':4},'sa':{'a':0,'k':0,'ix':5},'nm':'Transform'}],'nm':'Shape 1','np':3,'cix':2,'bm':0,'ix':1,'mn':'ADBE Vector Group','hd':false}],'ip':0,'op':658,'st':0,'bm':0},{'ddd':1,'ind':4,'ty':4,'nm':'Shape Layer 1','sr':1,'ks':{'o':{'a':0,'k':100,'ix':11},'rx':{'a':0,'k':312.125,'ix':8},'ry':{'a':1,'k':[{'i':{'x':[0.833],'y':[0.833]},'o':{'x':[0.167],'y':[0.167]},'t':0,'s':[0]},{'t':62,'s':[360]}],'ix':9},'rz':{'a':0,'k':138.742,'ix':10},'or':{'a':0,'k':[0,0,0],'ix':7},'p':{'a':0,'k':[491,406,0],'ix':2},'a':{'a':0,'k':[51,0,0],'ix':1},'s':{'a':0,'k':[249.792,249.792,249.792],'ix':6}},'ao':0,'shapes':[{'ty':'gr','it':[{'ind':0,'ty':'sh','ix':1,'ks':{'a':0,'k':{'i':[[0,0],[0,0],[0,0]],'o':[[0,0],[0,0],[0,0]],'v':[[51.071,102.142],[-51.071,0],[51.071,-102.142]],'c':true},'ix':2},'nm':'Path 1','mn':'ADBE Vector Shape - Group','hd':false},{'ty':'fl','c':{'a':0,'k':[0.639215686275,0.96862745098,0.709803921569,1],'ix':4},'o':{'a':0,'k':100,'ix':5},'r':1,'bm':0,'nm':'Fill 1','mn':'ADBE Vector Graphic - Fill','hd':false},{'ty':'tr','p':{'a':0,'k':[0,0],'ix':2},'a':{'a':0,'k':[0,0],'ix':1},'s':{'a':0,'k':[100,100],'ix':3},'r':{'a':0,'k':0,'ix':6},'o':{'a':0,'k':100,'ix':7},'sk':{'a':0,'k':0,'ix':4},'sa':{'a':0,'k':0,'ix':5},'nm':'Transform'}],'nm':'Shape 1','np':3,'cix':2,'bm':0,'ix':1,'mn':'ADBE Vector Group','hd':false}],'ip':0,'op':658,'st':0,'bm':0}],'markers':[]}";

//// Helpers

struct transform {
};


//// Sources

struct ImageSource { 
	struct ImageSource* prev;
	struct ImageSource* next;

};

struct PrecompSource {
	struct PrecompSource* prev;
	struct PrecompSource* next;
	int id;
	struct Layer* layer;
};

struct CharSource {
};

struct PlayerSource {
};

struct FontSource {
};





struct Font {
	struct Font* prev;
	struct Font* next;
	struct FontSource* font;
};

struct Player {
	struct Player* prev;
	struct Player* next;
};

struct Chars {
	struct CharSource* charSource;

};





//enum States {NoState = 0, Animation = 1, Layers = 2, Assets = 3, Chars = 4, Players = 5, Fonts = 6, ks = 7, ao = 8, bm = 9, ddd = 10, maskProperties = 11, ef = 12, shapes = 13, it = 14, t = 15, a = 16, m = 17, r = 18, p = 19, s = 20, sk = 21, sa = 22, o = 23, sw =  24, sc = 25, fc = 26, fh = 27, fs = 28, fb = 29, maxa = 31, mine = 32, maxe = 33, bo = 34, start  = 35, end = 36, Offset = 37, g = 38};

enum Scopes {
	noscope = 0,
	animation = 1,
	assets = 2,
	assets_layers = 403,
	assets_layers_shapes = 404,
	assets_layers_shapes_ty = 401,
	assets_layers_shapes_ks = 405,
	assets_layers_shapes_ks_k = 406,
	assets_layers_shapes_ks_k_e = 407,
	assets_layers_shapes_ks_k_s = 408,
	// 
	layers = 503,
	layers_shapes = 504,
	layers_shapes_ty = 501,
	layers_shapes_ks = 505,
	layers_shapes_ks_k = 506,
	layers_shapes_ks_k_e = 507,
	layers_shapes_ks_k_s = 508
	};

enum States {
	NoState,
	Start,
	ScopeOpen,
	ScopeClose,
	ScopeOpenInArray,
	ScopeCloseInArray,
	ArrayOpen,
	ArrayClose,
	KVSwitch,
	KVReadOpen,
	KVReading,
	KVReadClose,
	NewElement
	};

enum KeyValueState {Key, Value};

enum KeyValueState kvState = Key;

struct StateTrail {
	struct StateTrail* prev;
	struct StateTrail* next;
	enum States stateNow;
} *theState;

struct ScopeTrail {
	struct scopeTrail* start;
	struct ScopeTrail* prev;
	struct ScopeTrail* next;

	struct KeyValue* currentKeyValue;
	struct StateTrail* currentState;
	enum Scopes scope;
} *theScope;

string lastValue;
string currentValue;
string lastRead;

string currentReadValue;
string currentReadKey;

bool readingArray = false;
bool wasReadingArray = false;

struct ArrayTrail {
	struct ArrayTrail* prev;
	struct ArrayTrail* next;
	bool isRoot;
	struct ScopeTrail scopeHere;
} *arrayNow; 

// currently unused function, referred from checkCharacter (commented out over there)
int determineCurrentScope() {
	if (theState->stateNow == ScopeOpen || theState->stateNow == ArrayOpen) {

		if (currentValue == "assets") {
			EM_ASM(
				console.log('scope open');
			);

			theScope->scope = assets;
		}
	}
	return 1;
}
/////////////////////////////////////////////////////////////////////////////

int addState(enum States statePassed) {
	struct StateTrail* tempState;
	tempState = new StateTrail;
	theState->next = tempState;
	theState = theState->next;
	theState->stateNow = statePassed;
	theState->next = NULL;

	return 1;
}

int removeState() {
	struct StateTrail* tempState;
	tempState = new StateTrail;
	tempState = theState;
	tempState->prev = NULL;
	theState = theState->prev;
	theState->next = NULL;
	delete tempState;

	return 1;
}

int removeReadStates() {
	while (theState->stateNow == KVReading) {
		removeState();
	}
	return 1;
}

int addScope(enum Scopes scopePassed) {
	struct ScopeTrail* tempScope;
	tempScope = new ScopeTrail;
	theScope->next = tempScope;
	theScope = theScope->next;
	theScope->next = NULL;
	theScope->currentState = theState;
	theScope->scope = scopePassed;

	return 1;
}

int removeScope() {
	struct ScopeTrail* tempScope;
	tempScope = new ScopeTrail;
	tempScope = theScope;
	tempScope->prev = NULL;
	theScope = theScope->prev;
	theScope->next = NULL;
	delete tempScope;

	return 1;
}

int addArray() {
	struct ArrayTrail* tempArray;
	tempArray = new ArrayTrail;
	arrayNow->next = tempArray;
	arrayNow = arrayNow->next;
	arrayNow->next = NULL;

	return 1;
}

int removeArray() {
	struct ArrayTrail* tempArray;
	tempArray = new ArrayTrail;
	tempArray = arrayNow;
	tempArray->prev = NULL;
	arrayNow = arrayNow->prev;
	arrayNow->next = NULL;
	delete tempArray;

	return 1;
}

#include "properties.cpp"
#include "layers.cpp"
#include "shapes.cpp"
#include "associate.cpp"


int checkScope() {
	switch (theScope->scope) {
		case noscope:
			theScope->scope = animation;

			//determineCurrentScope();
			break;
		case animation:
			if (currentReadKey == "assets") {
				addScope(assets);
			} else if (currentReadKey == "layers") {
				addScope(layers);
			}
			break;
		case assets:
			if (currentReadKey == "layers") {
				addScope(assets_layers);
			}
			break;
		case assets_layers:
			if (currentReadKey == "shapes") {
				addScope(assets_layers_shapes);
			}
			break;
		case assets_layers_shapes_ty: //LayersShapes shape item's type found
			
			break;
		case assets_layers_shapes:
			if (currentReadKey == "ks") {
				addScope(assets_layers_shapes_ks);
			} else if (currentReadKey == "ty") {
				addScope(assets_layers_shapes_ty);
			}
			break;
		case assets_layers_shapes_ks:
			if (currentReadKey == "k") {
				addScope(assets_layers_shapes_ks_k);
			}
			break;
		case assets_layers_shapes_ks_k:
			if (currentReadKey == "e") {
				addScope(assets_layers_shapes_ks_k_e);
			}
			if (currentReadKey == "s") {
				addScope(assets_layers_shapes_ks_k_s);
			}
			break;
		//
		case layers:
			if (currentReadKey == "shapes") {
				addScope(layers_shapes);
			}
			break;
		case layers_shapes_ty: //LayersShapes shape item's type found
			
			break;
		case layers_shapes:
			if (currentReadKey == "ks") {
				addScope(layers_shapes_ks);
			} else if (currentReadKey == "ty") {
				addScope(layers_shapes_ty);
			}
			break;
		case layers_shapes_ks:
			if (currentReadKey == "k") {
				addScope(layers_shapes_ks_k);
			}
			break;
		case layers_shapes_ks_k:
			if (currentReadKey == "e") {
				addScope(layers_shapes_ks_k_e);
			}
			if (currentReadKey == "s") {
				addScope(layers_shapes_ks_k_s);
			}
			break;
		default:
			break;
	}

	return 1;
}

int readingDone() {
		if (theState->stateNow == ArrayOpen) {
			addKeyValue(currentKeyValue, currentReadKey, currentReadValue, true);
		} else {
			addKeyValue(currentKeyValue, currentReadKey, currentReadValue, false);
		}
		/*
		if (kvState == Key) {
			theScope->currentKeyValue->key = currentValue;
		}
		if (kvState == Value) {
			if (currentArrayOfString->value.size() > 0) {
				theScope->currentKeyValue->arrayValue = currentArrayOfString;
			} else {
				theScope->currentKeyValue->value = currentValue;
			}
		}
		*/
}

int checkCharacter(char& currentChar) {
	switch (currentChar) {
		case '{':
			kvState = Key;
			newKeyValueTrail();
			readingArray = false;
			if (theState->prev->stateNow == ArrayOpen) {
				addState(ScopeOpenInArray);
				if (theState->prev->stateNow != ScopeOpenInArray) {
					prepareContainer(true);
				}
			} else {
				addState(ScopeOpen);
				prepareContainer(false);
			}
			break;
		case '}':
			associateKeyValues();
			removeKeyValueTrail();
			removeScope();
			removeState();
			break;
		case '[':
			readingArray = true;
			addState(ArrayOpen);
			if (theState->prev->stateNow == ArrayOpen) {
				addChildArray(currentKeyValue);
			}
			break;
		case ']':
			readingArray = false;
			gotoParentArray(currentKeyValue);
			removeState();
			break;
		case ':':
			kvState = Value;
			break;
		case '\'':
			if (theState->stateNow == KVReading || theState->stateNow == KVReadOpen) {
				if (kvState == Value) {
					currentReadValue = currentValue;
					readingDone();
					kvState = Key;
				} else {
					currentReadKey = currentValue;
					checkScope();
				}
				removeReadStates();
				////////////// DEBUG stuff
					EM_ASM_({
						console.log('done reading');
					});
				//////////////////////// DEND */
			} else {
				addState(KVReadOpen);
				////////////// DEBUG stuff
					if (theState->prev->stateNow != KVReading) {
						currentValue.clear();
						EM_ASM_({
							console.log('start reading');
						});
					}
				//////////////////////// DEND */
			}
			break;
		case ',':
			//addState(NewElement);
			kvState = Key;
			break;
		default:
			if (	currentChar != ' ' &&
				currentChar != '\f' &&
				currentChar != '\n' &&
				currentChar != '\r' &&
				currentChar != '\t' &&
				currentChar != '\v') {
				if (theState->stateNow == KVOpen) {
					addState(KVReading);
				}
			} else {
				if (theState->stateNow == KVReading) {
					addState(KVReading);
				}
			}
	}

	if (theState->stateNow == KVReading) {
		//currentValue = currentValue + currentChar;
		//currentValue.append((char *)currentChar);
		currentValue.append(1, currentChar);
	}

	////////////// DEBUG stuff
	if (theState->stateNow == KVReading) {
		EM_ASM_({
			console.log(String.fromCharCode($0));
		}, (int)currentChar);
	}
	//////////////////////// DEND */

	////////////// DEBUG stuff
	if (currentReadKey == "assets") {
		EM_ASM_({
			console.log('found some assets');
		});
	}
	//////////////////////// DEND */
}


int deserialize() {
	//struct ScopeTrail* theScope;
	//struct StateTrail* theState;
	theScope = new ScopeTrail;
	theState = new StateTrail;
	theScope->prev = 0;
	theScope->next = 0;
	theScope->scope = noscope;
	theState->stateNow = Start;
	kvState = Key;


	for(char& currentChar : jsonString) {

		checkCharacter(currentChar);
		
	}
	return 1;
}


