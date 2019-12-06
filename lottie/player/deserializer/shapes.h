//// shapes

enum ShapesTy {
		_group = 0, //gr
		_shape = 1, //sh
		_ellipse = 2, //el
		_rect = 3, //rc
		_star = 4, //sr
		_fill = 5, //fl
		_gFill = 6, //gf
		_gStroke = 7, //gs
		_stroke = 8, //st
		_merge = 9, //mm
		_trim = 10, //tm
		_roundedCorners = 11, //rd
		_repeater = 12, // rp
		_transform = 13 // tr
		
	};

struct alignas(ALIGNSIZE) ShapesItem {
	struct ShapesItem* start = NULL;
	struct ShapesItem* next = NULL;
	struct ShapesItem* prev = NULL;

	/*
	struct ShapesShape* shape; // sh
	struct ShapesEllipse* ellipse; // el
	struct ShapesRect* rect; // rc
	struct ShapesStar* star; // sr
	struct ShapesFill* fill; // fl
	struct ShapesGFill* gFill; // gf
	struct ShapesGStroke* gStroke; // gs
	struct ShapesStroke* stroke; // st
	struct ShapesMerge* merge; // mm
	struct ShapesTrim* trim; // tm
	struct ShapesGroup* group; // gr
	struct ShapesRoundedCorners* roundedCorners; // rd
	struct ShapesRepeater* repeater; // rp
	struct ShapesTransform* transform; // tr
	*/
	void* item;

	enum ShapesTy ty;
	struct PropertiesShape* ks;
	char mn[KVLEN]; // match name
	char nm[KVLEN]; // name
	int d; // direction
	struct PropertiesValue* r; // rotation (radius for roundedCorners[rd])
	struct PropertiesMultiDimensional* s; // size (scale for transform[tr], start point for gFill[gf])
	struct PropertiesMultiDimensional* p; // position
	struct PropertiesValue* o; // opacity [offset for repeater[rp]
	struct PropertiesMultiDimensional* c; // color (number of copies for repeater[rp])
	int np; // number of properties
	struct PropertiesMultiDimensional* e; // end point
	struct PropertiesValue* h; // highlight length
	struct PropertiesMultiDimensional* a; // anchor point (highlight angle for gFill[gf] and gStroke[gs])
	struct PropertiesValue* sk; // skew
	struct PropertiesValue* sa; // skew axis

	void* g; // gradient colors - to be researched further

	int t; // type [1 for linear, 2 for radial]
	struct PropertiesValue* w; // stroke width
	struct HelpersLineCap* lc; // line cap
	struct HelpersLineJoin* lj; // line join
	int ml; // miter limit
	int mm; // merge mode
	struct HelpersTransform* tr; // transform
	
	struct ShapesItem* it;
	
} *currentShapesItem;

/*
struct alignas(ALIGNSIZE) ShapesGroup {
	string mn; // match name
	string nm; // name
	string np; // number of properties

	enum ShapesTy ty = gr;

	struct ShapesItem* it; // item

	struct ShapesGroup* parentGroup;
} *currentShapesGroup;

struct alignas(ALIGNSIZE) ShapesShape {
	string mn; // match name
	string nm; // name
	int d; // direction

	enum ShapesTy ty = sh;

	struct PropertiesShape* ks;
	struct PropertiesShapeKeyframed* ksKeyframed;

	struct ShapesGroup *parentGroup;
} *currentShapesShape;
*/

