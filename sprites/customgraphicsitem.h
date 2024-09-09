#ifndef CUSTOMGRAPHICSITEM_H
#define CUSTOMGRAPHICSITEM_H

#include <QGraphicsRectItem>

class CustomGraphicsItem : public QGraphicsRectItem
{
public:
    CustomGraphicsItem(std::string, int, int, QGraphicsItem* _parent = nullptr);
    void move(int, int);
private:
    std::string assetId;
};

#endif // CUSTOMGRAPHICSITEM_H
