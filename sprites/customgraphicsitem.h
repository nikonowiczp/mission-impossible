#ifndef CUSTOMGRAPHICSITEM_H
#define CUSTOMGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

///
/// \brief The CustomGraphicsItem class representing objects on the game map.
///
/// The CustomGraphicsItem class derives from QGraphicsPixmapItem. Its main responsibility is to render the object with the given asset on a given position.
class CustomGraphicsItem : public QGraphicsPixmapItem
{
public:

    ///
    /// CustomGraphicsItem constructor.
    /// @param _assetPath   Path to the asset representing the object.
    /// @param _assetId     Id of the object as int.
    /// @param _x           Initial x coordinate.
    /// @param _y           Initial y coordinate.
    /// @param _parent      Pointer to the QGraphicsItem parent of the object.
    CustomGraphicsItem(std::string _assetPath, int _assetId, int _x, int _y, int _radius, QGraphicsItem* _parent);

    ///
    /// Public method used to move the object to the given place on map.
    /// @param _x   X coordinate of the target position.
    /// @param _y   Y coordinate of the target position.
    void Move(int _x, int _y);
private:
    int assetId;
    std::string assetPath;
    int radius;
};

#endif // CUSTOMGRAPHICSITEM_H
