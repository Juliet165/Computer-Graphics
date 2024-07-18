# Техническая документация

## Лабораторная работа №1 "Цветовые модели"
Данный проект разработан для выполнения Лабораторной работы №1 по учебному предмету "Программирование компьютерной графики".

## Используемые технологии

- **Язык программирования**: C++
- **Среда разработки**: Qt Creator 4.11.1
- **Комплект**: Desktop Qt 5.15.2 MinGW 64-bit

## Основные компоненты приложения

### Интерфейсные элементы

- **Кнопка**: отображает текущий цвет и позволяет выбирать цвет из палитры.
- **Ползунки**: три ползунка для регулировки компонентов цвета.
- **Комбобоксы**: три комбобокса для выбора цветовых моделей.
- **Поля ввода**: отображают и позволяют изменять компоненты цвета.
- **Лейблы**: показывают выбранные цветовые модели.

### Используемые библиотеки

- `QWidget`: основное поле приложения.
- `QLabel`: надписи около полей ввода, отображающие выбранную цветовую модель.
- `QSpinBox`: поля ввода для числовых значений.
- `QComboBox`: комбобоксы для выбора цветовых моделей.
- `QPainter`: библиотека для работы с цветом в Qt.
- `QGridLayout`: для разметки интерфейса приложения.
- `QSlider`: ползунки для регулировки значений цвета.
- `QPushButton`: кнопка для выбора цвета.
- `QColorDialog`: всплывающее окно для выбора цвета из палитры.

## Функциональные возможности

1. **Выбор цвета с помощью кнопки**:
   - Кнопка в правом углу экрана залита выбранным цветом.
   - При нажатии на кнопку открывается диалоговое окно для выбора цвета из палитры.

2. **Регулировка цвета с помощью ползунков**:
   - Ползунки позволяют плавно изменять текущий цвет.
   - Значения в полях ввода автоматически изменяются при перемещении ползунков.

3. **Выбор и конвертация цветовых моделей**:
   - Три комбобокса позволяют выбрать цветовые модели для конвертации цветов.
   - Количество полей ввода варьируется в зависимости от выбранной цветовой модели (четыре поля для CMYK).
   - Поля ввода блокируют некорректный ввод данных.
   - Автоматический пересчет значений при изменении параметров.
   - Предупреждение при некорректном преобразовании из XYZ в RGB.

## Основные файлы

- `colors.cpp`: реализация основных функций работы с цветами.
- `colors.h`: заголовочный файл с описанием функций и классов.
- `main.cpp`: основной файл, запускающий приложение.

Остальные файлы являются вспомогательными и не требуют изменений.

## Папка Executable

Папка `Executable` содержит:

- Сборку приложения (.exe файл).
- Все необходимые библиотеки и файлы для корректного запуска приложения.

## Установка и запуск

1. **Склонируйте репозиторий**:
    ```sh
    git clone https://github.com/your-username/graphics-lab1-colormodels.git
    cd graphics-lab1-colormodels
    ```

2. **Откройте проект в Qt Creator**:
    - Запустите Qt Creator.
    - Откройте файл проекта (.pro) из скачанного репозитория.

3. **Соберите и запустите проект**:
    - Нажмите `Ctrl+R` для сборки и запуска проекта.