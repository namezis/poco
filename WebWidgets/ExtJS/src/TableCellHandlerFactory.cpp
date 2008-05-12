//
// TableCellHandlerFactory.cpp
//
// $Id: //poco/Main/WebWidgets/ExtJS/src/TableCellHandlerFactory.cpp#3 $
//
// Library: ExtJS
// Package: Core
// Module:  TableCellHandlerFactory
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


#include "Poco/WebWidgets/ExtJS/TableCellHandlerFactory.h"
#include "Poco/WebWidgets/CheckButtonCell.h"
#include "Poco/WebWidgets/TextEditCell.h"
#include "Poco/WebWidgets/TextFieldCell.h"
#include "Poco/WebWidgets/ComboBoxCell.h"
#include "Poco/WebWidgets/ButtonCell.h"
#include "Poco/WebWidgets/NumberFieldCell.h"


namespace Poco {
namespace WebWidgets {
namespace ExtJS {


TableCellHandlerFactory::TableCellHandlerFactory()
{
	{
		TableCellHandler<CheckButtonCell>::Ptr pHandle(new TableCellHandler<CheckButtonCell>("Ext.form.Checkbox", true, true));
		pHandle->addDynamic("checked", &CheckButtonCell::getBool);
		registerFactory(typeid(CheckButtonCell), pHandle);
	}
	{
		TableCellHandler<TextEditCell>::Ptr pHandle(new TableCellHandler<TextEditCell>("Ext.form.TextArea", true, true));
		pHandle->addDynamic("value", &TextEditCell::getString);
		registerFactory(typeid(TextEditCell), pHandle);
	}
	{
		TableCellHandler<TextFieldCell>::Ptr pHandle(new TableCellHandler<TextFieldCell>("Ext.form.TextField", true, false));
		pHandle->addDynamic("value", &TextFieldCell::getString);
		registerFactory(typeid(TextFieldCell), pHandle);
	}
	{
		TableCellHandler<NumberFieldCell>::Ptr pHandle(new TableCellHandler<NumberFieldCell>("Ext.form.NumberField", true, false));
		pHandle->addDynamic("value", &NumberFieldCell::getString);
		registerFactory(typeid(NumberFieldCell), pHandle);
	}
	{
		TableCellHandler<ComboBoxCell>::Ptr pHandle(new TableCellHandler<ComboBoxCell>("Ext.form.ComboBox", true, false));
		pHandle->addDynamic("value", &ComboBoxCell::getString);
		registerFactory(typeid(ComboBoxCell), pHandle);
	}
	{
		TableCellHandler<ButtonCell>::Ptr pHandle(new TableCellHandler<ButtonCell>("Ext.Button", false, true));
		pHandle->addDynamic("text", &ButtonCell::getString);
		registerFactory(typeid(ButtonCell), pHandle);
	}
	{
		TableCellHandler<ImageButtonCell>::Ptr pHandle(new TableCellHandler<ImageButtonCell>(false, true));
		registerFactory(typeid(ImageButtonCell), pHandle);
	}
}


TableCellHandlerFactory::~TableCellHandlerFactory()
{
}


TableCellHandlerFactory& TableCellHandlerFactory::instance()
{
	static TableCellHandlerFactory fct;
	return fct;
}


AbstractTableCellHandler::Ptr TableCellHandlerFactory::factory(const Cell::Ptr& t) const
{
	ConstIterator it = _handlers.find(Type(t->type()));
	if (it == _handlers.end())
		throw NotFoundException();

	AbstractTableCellHandler::Ptr pCopy = it->second->clone();
	pCopy->init(t);
	return pCopy;
}


void TableCellHandlerFactory::registerFactory(const Type& t, AbstractTableCellHandler::Ptr ptr)
{
	std::pair<Iterator, bool> res = _handlers.insert(std::make_pair(t, ptr));
	if (!res.second)
		res.first->second = ptr;
}


void TableCellHandlerFactory::registerFactory(const std::type_info& t, AbstractTableCellHandler::Ptr ptr)
{
	registerFactory(Type(t), ptr);
}


} } } // namespace Poco::WebWidgets::ExtJS
