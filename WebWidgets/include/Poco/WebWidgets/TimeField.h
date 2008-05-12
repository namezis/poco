//
// TimeField.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/TimeField.h#4 $
//
// Library: WebWidgets
// Package: Controls
// Module:  TimeField
//
// Definition of the TimeField class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
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


#ifndef WebWidgets_TimeField_INCLUDED
#define WebWidgets_TimeField_INCLUDED


#include "Poco/WebWidgets/TextField.h"


namespace Poco {
namespace WebWidgets {


class WebWidgets_API TimeField: public TextField
	/// A TimeField
{
public:
	typedef Poco::AutoPtr<TimeField> Ptr;

	enum Format
	{
		FMT_AMPM = 0,
		FMT_24H,
		FMT_AMPM_WITHSECONDS,
		FMT_24H_WITHSECONDS
	};

	TimeField();
		/// Creates an anonymous TimeField.

	TimeField(const std::string& name);
		/// Creates a named TimeField.

	TimeField::Format getFormat() const;
		/// Returns the time format

	void setFormat(TimeField::Format fmt);
		/// Sets the time format

protected:
	TimeField(const std::string& name, const std::type_info& type);
		/// Creates a TimeField and assigns it the given name.

	TimeField(const std::type_info& type);
		/// Creates a TimeField.

	~TimeField();
		/// Destroys the TimeField.

};


} } // namespace Poco::WebWidgets


#endif // WebWidgets_TimeField_INCLUDED
