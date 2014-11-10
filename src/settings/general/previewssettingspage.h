/***************************************************************************
 *   Copyright (C) 2006 by Peter Penz <peter.penz19@gmail.com>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef PREVIEWSSETTINGSPAGE_H
#define PREVIEWSSETTINGSPAGE_H

#include <settings/settingspagebase.h>

class QSpinBox;
class QListView;
class QModelIndex;

/**
 * @brief Allows the configuration of file previews.
 */
class PreviewsSettingsPage : public SettingsPageBase
{
    Q_OBJECT

public:
    PreviewsSettingsPage(QWidget* parent);
    virtual ~PreviewsSettingsPage();

    /**
     * Applies the general settings for the view modes
     * The settings are persisted automatically when
     * closing Dolphin.
     */
    virtual void applySettings() Q_DECL_OVERRIDE;

    /** Restores the settings to default values. */
    virtual void restoreDefaults() Q_DECL_OVERRIDE;

protected:
    virtual void showEvent(QShowEvent* event) Q_DECL_OVERRIDE;

private slots:
    void configureService(const QModelIndex& index);

private:
    void loadPreviewPlugins();
    void loadSettings();

private:
    bool m_initialized;
    QListView *m_listView;
    QStringList m_enabledPreviewPlugins;
    QSpinBox* m_remoteFileSizeBox;
};

#endif
