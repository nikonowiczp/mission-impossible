#ifndef CUSTOMGRAPHICSITEM_H
#define CUSTOMGRAPHICSITEM_H

#include <QGraphicsRectItem>

class CustomGraphicsItem : public QGraphicsRectItem
{
public:
    CustomGraphicsItem(std::string, int, int, int, int, QGraphicsItem* _parent = nullptr);
    void move(int, int);
private:
    int assetId;
    std::string assetPath;
    int radius;
};

#endif // CUSTOMGRAPHICSITEM_H
