#pragma once

#include <string>
#include <functional>

namespace Kyuubi {

	//EVENTS ARE BLOCKING

	enum class EventType {
		None = 0
	};

	enum EventCategory {
		None = 0
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;}
	
	class Event {
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
		virtual int GetCategoryFlags() const = 0;

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

	protected:
		bool handled = false;
	};
}