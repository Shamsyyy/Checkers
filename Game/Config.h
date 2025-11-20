#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../Models/Project_path.h"

// Класс для работы с файлом настроек settings.json.
// Позволяет перечитывать файл и удобно доставать отдельные параметры.
class Config
{
  public:
    Config()
    {
        // При создании объекта сразу загружаем настройки из файла
        reload();
    }

    // Перечитывает настройки из файла settings.json.
    // Используется при запуске игры и при повторном старте партии.
    void reload()
    {
        std::ifstream fin(project_path + "settings.json");
        fin >> config;   // загружаем JSON в объект config
        fin.close();
    }

    // Упрощённый доступ к настройкам.
    // Пример: config("Bot", "BotDelayMS") вернёт значение config["Bot"]["BotDelayMS"].
    auto operator()(const string &setting_dir, const string &setting_name) const
    {
        return config[setting_dir][setting_name];
    }

  private:
    // Весь объект настроек, считанный из файла settings.json.
    json config;
};
