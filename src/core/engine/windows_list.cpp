// SPDX-FileCopyrightText: 2022 Mikhail Zolotukhin <mail@gikari.com>
// SPDX-License-Identifier: MIT

#include "windows_list.hpp"
#include "engine/surface.hpp"
#include "logger.hpp"

namespace Bismuth
{

void WindowsList::add(PlasmaApi::Client client)
{
    m_windowMap.insert_or_assign(client, Window(client));
}

void WindowsList::remove(PlasmaApi::Client client)
{
    m_windowMap.erase(client);
}

std::vector<Window> WindowsList::visibleWindowsOn(const Surface &surface)
{
    auto result = std::vector<Window>();
    for (auto [_, window] : m_windowMap) {
        if (window.visibleOn(surface)) {
            result.push_back(window);
        }
    }
    return result;
}

}