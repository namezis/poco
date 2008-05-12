//
// BoolFormatter.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/BoolFormatter.h#1 $
//
// Library: WebWidgets
// Package: ChangeThis
// Module:  BoolFormatter
//
// Definition of the BoolFormatter class.
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


#ifndef WebWidgets_BoolFormatter_INCLUDED
#define WebWidgets_BoolFormatter_INCLUDED


#include "Poco/WebWidgets/Formatter.h"


namespace Poco {
namespace WebWidgets {


class WebWidgets_API BoolFormatter: public Formatter
	/// BoolFormatter serializes boolean values
{
public:
	typedef Poco::AutoPtr<BoolFormatter> Ptr;

	BoolFormatter();
		/// Creates the BoolFormatter.

	std::string format(const Poco::Any& value) const;

	Poco::Any parse(const std::string& value) const;

protected:
	~BoolFormatter();
		/// Destroys the BoolFormatter.
};


} } // namespace Poco::WebWidgets


#endif // WebWidgets_BoolFormatter_INCLUDED
