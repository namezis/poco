//
// TextEditCell.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/TextEditCell.h#2 $
//
// Library: WebWidgets
// Package: Controls
// Module:  TextEditCell
//
// Definition of the TextEditCell class.
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


#ifndef WebWidgets_TextEditCell_INCLUDED
#define WebWidgets_TextEditCell_INCLUDED


#include "Poco/WebWidgets/Cell.h"
#include "Poco/WebWidgets/Delegate.h"


namespace Poco {
namespace WebWidgets {


class WebWidgets_API TextEditCell: public Cell
	/// A Cell for a TextExit.
{
public:
	typedef Poco::AutoPtr<TextEditCell> Ptr;

	Delegate textChanged;

	TextEditCell(View* pOwner);
		/// Creates a TextEditCell.

	void setPlaceHolder(const std::string& text);
		/// Sets the TextField's placeholder content.

	const std::string& getPlaceHolder() const;
		/// Returns the TextField's placeholder content.

	void setHeightInPixel(int height);
		/// Sets the height in pixel. A negative value equals autoSize.

	int getHeightInPixel() const;
		/// Returns the height in pixel. A negative value equals autoSize.

	void setGrow(bool grow);
		/// Specifies if the control can grow with its content.
		
	bool getGrow() const;
		/// Returns if the control can grow with its content.

	// Cell
	void handleForm(const std::string& field, const std::string& value);

protected:
	~TextEditCell();
		/// Destroys the TextEditCell.

	TextEditCell(View* pOwner, const std::type_info& type);
		/// Creates a TextEditCell.

private:
	std::string _placeHolder;
	int         _heightInPixel;
	bool        _canGrow;
};


//
// inlines
//

inline const std::string& TextEditCell::getPlaceHolder() const
{
	return _placeHolder;
}


inline void TextEditCell::setPlaceHolder(const std::string& text)
{
	_placeHolder = text;
}


inline void TextEditCell::setHeightInPixel(int height)
{
	_heightInPixel = height;
}


inline int TextEditCell::getHeightInPixel() const
{
	return _heightInPixel;
}


inline void TextEditCell::setGrow(bool grow)
{
	_canGrow = grow;
}


inline bool TextEditCell::getGrow() const
{
	return _canGrow;
}


} } // namespace Poco::WebWidgets


#endif // WebWidgets_TextEditCell_INCLUDED
