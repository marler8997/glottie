// functions

struct ShapesItem* newShapesShape(enum ShapesTy passedTy, struct ShapesItem* passedShapesItem) {
	if (passedShapesItem == NULL) {
		passedShapesItem = new ShapesItem;
	}

	if (passedTy == sh) {
		passedShapesItem->item = new ShapesShape;
		passedShapesItem->ty = passedTy;
		currentShapesShape = passedShapesItem->item;
	} else if (passedTy == el) {
	} else if (passedTy == rc) {
	} else if (passedTy == sr) {
	} else if (passedTy == fl) {
	} else if (passedTy == gf) {
	} else if (passedTy == gs) {
	} else if (passedTy == st) {
	} else if (passedTy == mm) {
	} else if (passedTy == tm) {
	} else if (passedTy == gr) {
		passedShapesItem->item = new ShapesGroup;
		passedShapesItem->ty = passedTy;
		currentShapesGroup = passedShapesItem->item;
	} else if (passedTy == rd) {
	} else if (passedTy == rp) {
	} else if (passedTy == tr) {
	} 
        return passedShapesItem;
}


//////////// assign values

