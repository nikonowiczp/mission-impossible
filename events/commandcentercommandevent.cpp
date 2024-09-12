#include "commandcentercommandevent.h"

CommandCenterCommandEvent::CommandCenterCommandEvent(std::unique_ptr<Point> point, int id) {
    this->location = std::move(point);
    this->id = id;
}
