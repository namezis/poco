//
// Event.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/Event.h#3 $
//
// Library: WebWidgets
// Package: Core
// Module:  Event
//
// Definition of the Event class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef WebWidgets_Event_INCLUDED
#define WebWidgets_Event_INCLUDED


#include "Poco/WebWidgets/WebWidgets.h"
#include "Poco/WebWidgets/View.h"


namespace Poco {
namespace WebWidgets {


template <class V>
class Event
	/// This class holds arguments for events.
{
public:
	Event(typename V* pView):
		/// Creates an Event for the given View.
		_pView(pView)
	{
	}
				
	Event(const Event& event):
		/// Creates the Event by copying another one.
		_pView(event._pView)
	{
	}
				
	~Event()
		/// Destroys the Type.
	{
	}
		
	Event& operator = (const Event& event)
		/// Assignment operator.
	{
		if (&event != this)
		{
			_pView = event._pView;
		}
		return *this;
	}
		
	V& view() const
		/// Returns the View that was the source of the event.
	{
		return *_pView;
	}
	
	typename V* viewPtr() const
		/// Returns the View that was the source of the event.
	{
		return _pView;
	}
	
				
private:
	Event();

	typename V* _pView;
};


} } // namespace Poco::WebWidgets


#endif // WebWidgets_Event_INCLUDED
