#include "humanfoundevent.h"

HumanFoundEvent::HumanFoundEvent(std::unique_ptr<Point> _location) {
    this->Location = std::move(_location);
}
