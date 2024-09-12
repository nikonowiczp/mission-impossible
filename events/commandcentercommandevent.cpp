#include "commandcentercommandevent.h"

CommandCenterCommandEvent::CommandCenterCommandEvent(std::unique_ptr<Point> point, int id, int skew) {
    this->location = std::move(point);
    this->id = id;
    this->skew = skew;
}
