//
// TabViewRenderer.h
//
// $Id: //poco/Main/WebWidgets/ExtJS/include/Poco/WebWidgets/ExtJS/TabViewRenderer.h#1 $
//
// Library: ExtJS
// Package: Core
// Module:  TabViewRenderer
//
// Definition of the TabViewRenderer class.
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


#ifndef ExtJS_TabViewRenderer_INCLUDED
#define ExtJS_TabViewRenderer_INCLUDED


#include "Poco/WebWidgets/ExtJS/LayoutRenderer.h"


namespace Poco {
namespace WebWidgets {

	class TabView;

namespace ExtJS {


class ExtJS_API TabViewRenderer: public LayoutRenderer
	/// TabViewRenderer renders a TabView
{
public:
	TabViewRenderer();
		/// Creates the TabViewRenderer.

	virtual ~TabViewRenderer();
		/// Destroys the TabViewRenderer.

	void renderHead(const Renderable* pRenderable, const RenderContext& context, std::ostream& ostr);
		/// Emits code for the page header to the given output stream.

private:
	void renderParameters(const TabView* pTabView, const RenderContext& context, std::ostream& ostr);

	void visitChildren(const TabView* pTabView, const RenderContext& context, std::ostream& ostr);
};


} } } // namespace Poco::WebWidgets::ExtJS


#endif // ExtJS_TabViewRenderer_INCLUDED
