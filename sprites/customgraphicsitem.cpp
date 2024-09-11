#include "customgraphicsitem.h"


CustomGraphicsItem::CustomGraphicsItem(std::string _assetPath, int _assetId, int _x, int _y, int _radius, QGraphicsItem* _parent) : QGraphicsPixmapItem(_parent)
{
    this->assetPath = _assetPath;
    this->assetId = _assetId;
    this->radius = _radius;
    QRectF _targetRect(0, 0, _radius*2, _radius*2);
    QPixmap _originalPixmap(QString::fromStdString(_assetPath));
    QPixmap _scaledPixmap = _originalPixmap.scaled(_targetRect.size().toSize(), Qt::IgnoreAspectRatio);
    setPixmap(_scaledPixmap);
    setPos(_x-_radius, _y-_radius);
}

void CustomGraphicsItem::Move(int _x, int _y)
{
    setPos(_x-this->radius, _y-this->radius);
}

