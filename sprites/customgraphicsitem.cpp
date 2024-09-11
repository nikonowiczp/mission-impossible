#include "customgraphicsitem.h"


CustomGraphicsItem::CustomGraphicsItem(std::string _assetPath, int _assetId, int _x, int _y, int _radius, QGraphicsItem* _parent) : QGraphicsRectItem(_parent)
{
    this->assetPath = _assetPath;
    this->assetId = _assetId;
    this->radius = _radius;
    setRect(_x-_radius, _y-_radius, _radius*2, _radius*2);
}

void CustomGraphicsItem::move(int _x, int _y)
{
    setPos(_x-this->radius, _y-this->radius);
}

