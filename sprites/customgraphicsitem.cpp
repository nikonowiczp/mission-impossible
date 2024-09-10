#include "customgraphicsitem.h"


CustomGraphicsItem::CustomGraphicsItem(std::string _assetId, int _x, int _y, QGraphicsItem* _parent) : QGraphicsRectItem(_parent)
{
    this->assetId = _assetId;
    setRect(_x, _y, 100, 100);
}

void CustomGraphicsItem::move(int _x, int _y)
{
    setPos(_x, _y);
}

