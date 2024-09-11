#ifndef CUSTOMGRAPHICSITEM_H
#define CUSTOMGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class CustomGraphicsItem : public QGraphicsPixmapItem
{
public:
    CustomGraphicsItem(std::string, int, int, int, int, QGraphicsItem* _parent = nullptr);
    void Move(int, int);
private:
    int assetId;
    std::string assetPath;
    int radius;
};

#endif // CUSTOMGRAPHICSITEM_H
