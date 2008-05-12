//
// ImageButton.cpp
//
// $Id: //poco/Main/WebWidgets/src/ImageButton.cpp#6 $
//
// Library: WebWidgets
// Package: Controls
// Module:  ImageButton
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


#include "Poco/WebWidgets/ImageButton.h"
#include "Poco/WebWidgets/ImageButtonCell.h"


namespace Poco {
namespace WebWidgets {


ImageButton::ImageButton(const std::string& name, Image::Ptr img, const std::type_info& type):
	Button(name, type, new ImageButtonCell(this, img))
{
}


ImageButton::ImageButton(Image::Ptr img, const std::type_info& type):
	Button(type, new ImageButtonCell(this, img))
{
}


ImageButton::ImageButton(const std::string& name, Image::Ptr img):
	Button(name, typeid(ImageButton), new ImageButtonCell(this, img))
{
}


ImageButton::ImageButton(Image::Ptr img):
	Button(typeid(ImageButton), new ImageButtonCell(this, img))
{
}


ImageButton::~ImageButton()
{
}


void ImageButton::setImage(Image::Ptr img)
{
	cell<ImageButtonCell>()->setImage(img);
}


Image::Ptr ImageButton::getImage() const
{
	return cell<ImageButtonCell>()->getImage();
}


void ImageButton::setShowText(bool val)
{
	cell<ImageButtonCell>()->setShowText(val);
}


bool ImageButton::getShowText() const
{
	return cell<ImageButtonCell>()->getShowText();
}


} } // namespace Poco::WebWidgets
