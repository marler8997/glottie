
struct XY {
	int x;
	int y;
};

struct Vertex {
	GLfloat position[4];
};

struct ArrayOfVertex {
	struct ArrayOfVertex* start;
	struct ArrayOfVertex* next;
	struct ArrayOfVertex* prev;

	struct Vertex* vertex;
};

struct ArrayOfFloat {
	struct ArrayOfFloat* parent = NULL; // only one
	struct ArrayOfFloat* child = NULL; // only one
	float isSubArray = false;
	vector<float> value;
} *currentArrayOfFloat;

struct alignas(128) ValuesVector {
//struct ValuesVector {
	struct ValuesVector* start = NULL;
	struct ValuesVector* prev = NULL;
	struct ValuesVector* next = NULL;
	//string value;
	char value[20];
};

struct alignas(32) ArrayOfString {
//struct ArrayOfString {
	struct ArrayOfString* root = NULL;
	struct ArrayOfString* parent = NULL; // only one
	struct ArrayOfString* child = NULL; // only one
	//float isSubArray = false;
	struct ValuesVector* vector = NULL;
} *currentArrayOfString;

struct alignas(256) KeyValue {
//struct KeyValue {
	struct KeyValue* start = NULL;
	struct KeyValue* next = NULL;
	struct KeyValue* prev = NULL;

	//string key;
	char key[20];
	//string value = NULL;
	char value[20];
	struct ArrayOfString* arrayValue = NULL;
} *currentKeyValue;

struct alignas(32) KeyValueTrail {
//struct KeyValueTrail {
	struct KeyValueTrail* start = NULL;
	struct KeyValueTrail* next = NULL;
	struct KeyValueTrail* prev = NULL;

	struct KeyValue* keyValue = NULL;
} *currentKeyValueTrail;


