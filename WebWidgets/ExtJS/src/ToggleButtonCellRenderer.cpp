//
// ToggleButtonCellRenderer.cpp
//
// $Id: //poco/Main/WebWidgets/ExtJS/src/ToggleButtonCellRenderer.cpp#4 $
//
// Library: ExtJS
// Package: Core
// Module:  ToggleButtonCellRenderer
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


#include "Poco/WebWidgets/ExtJS/ToggleButtonCellRenderer.h"
#include "Poco/WebWidgets/ExtJS/FormRenderer.h"
#include "Poco/WebWidgets/ExtJS/Utility.h"
#include "Poco/WebWidgets/WebApplication.h"
#include "Poco/WebWidgets/ToggleButtonCell.h"


namespace Poco {
namespace WebWidgets {
namespace ExtJS {


ToggleButtonCellRenderer::ToggleButtonCellRenderer()
{
}


ToggleButtonCellRenderer::~ToggleButtonCellRenderer()
{
}


void ToggleButtonCellRenderer::renderBody(const Renderable* pRenderable, const RenderContext& context, std::ostream& ostr)
{
}


void ToggleButtonCellRenderer::renderProperties(const ToggleButtonCell* pToggleButtonCell, std::ostream& ostr)
{
	if (!pToggleButtonCell->getLabel().empty())
		ostr << "boxLabel:'" << Utility::safe(pToggleButtonCell->getLabel()) << "',";
	ostr << "checked:" << (pToggleButtonCell->isChecked()?"true":"false") << ",";
	Utility::writeCellProperties(pToggleButtonCell, ostr);
	//tooltip is not supported by togglebutton
	std::string tooltip (pToggleButtonCell->getToolTip());
	if (!tooltip.empty())
		ostr << ",listeners:{render:function(c){c.getEl().dom.qtip='" << Utility::safe(tooltip) << "'; c.getEl().dom.qclass = 'x-form-tip';}}";
	if (pToggleButtonCell->getOwner() && !pToggleButtonCell->getOwner()->getName().empty())
	{
		WebApplication::instance().registerFormProcessor(pToggleButtonCell->getOwner()->getName(), const_cast<ToggleButtonCell*>(pToggleButtonCell));
	}
}


} } } // namespace Poco::WebWidgets::ExtJS
