/* DrawingItemFactory.h
 *
 * Copyright (C) 2013-2014 Jason Allen
 *
 * This file is part of the Jade Diagram Editor.
 *
 * Jade is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Jade is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Jade.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef DRAWINGITEMFACTORY_H
#define DRAWINGITEMFACTORY_H

#include <DrawingTypes.h>

class DrawingItemFactory : public QObject
{
	Q_OBJECT

private:
	QList<DrawingItem*> mItems;
	QHash<QString, QVariant> mDefaultProperties;

public:
	DrawingItemFactory();
	~DrawingItemFactory();

	DrawingItemFactory& operator=(const DrawingItemFactory& factory);

public slots:
	void setDefaultProperties(const QHash<QString, QVariant>& defaultProperties);
public:
	QHash<QString, QVariant> defaultProperties() const;
	bool containsDefaultProperty(const QString& key) const;
	void setDefaultPropertyValue(const QString& key, const QVariant& value);
	QVariant defaultPropertyValue(const QString& key) const;

public:
	void registerItem(DrawingItem* item);
	void clear();
	bool isEmpty() const;

	DrawingItem* create(const QString& key) const;
};

#endif
