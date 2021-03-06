# Лабораторная работа #2: "Разработка библиотеки"

## Цели

  1. Получить первичное знакомство с системой сборки CMake.
  1. Познакомиться с IDE Qt Creator.
  1. Познакомиться с техникой написания unit-тестов при помощи инструмента
     Google Test.

## Задачи

  1. Спроектировать API для своего класса и оформить его в виде заголовочного
     файла.
  1. Реализовать данный API на языке С++, с целью сборки его в виде статической
     библиотеки.
  1. Покрыть свой класс unit-тестами.

## Типичные ошибки

  1. Тщательно позаботьтесь о качестве вашего кода и API в частности. Давайте
     понятные имена своим переменным, не используйте сокращений, отделяйте
     логически несвязанные блоки кода пустыми строками, и так далее.
  1. Не нужно добавлять никаких приложений, использующих ваш класс. Никаких
     сэмплов и функций `main`. Только сборка с тестами. Тесты — это лучшая
     иллюстрация работы с вашим классом, это "исполняемая документация".
  1. Работу нужно продолжать в своей личной директории, новых папок создавать не
     нужно.
  1. Оформление тестов:
     - Во всех тестах должны быть явные секции Arrange, Act, Assert.
     - Как правило должна быть только одна конструкция Assert.
     - Тесты должны читаться как реальный код, давайте переменным нормальные
       имена.
  1. Не заливайте никаких лишних файлов:
    - Бинарные файлы (результат компиляции)
    - Проекты, сгенерированные CMake (Microsoft Visual Studio и другие)
  1. Покрытие кода должно оставаться 100%.

## Детальные инструкции

### Предварительная настройка

  1. Установите приложение CMake.
  1. Установите IDE Qt Creator. Сами библиотеки Qt нам не понадобятся,
     поэтому их можно не инсталлировать.
  1. Перед выполнением лабораторной работы получите последнюю версию кодов из
     репозитория. Вот [примерные инструкции][git-pull] как добавить `upstream` и
     обновиться до актуального состояния.

        $ cd devtools-course-practice
        $ git checkout master
        $ git fetch upstream
        $ git merge upstream/master
        $ git checkout -b lab2-simple-calculator

  1. Далее полезно убедиться, что проект успешно собирается и проходит все
     тесты. Для этого можно воспользоваться скриптом `code/build-and-test.sh`,
     но к сожалению он работает только на UNIX-подобных системах, на которых
     функционируют bash-скрипты.

        $ cd ./code
        $ ./build-and-test.sh

  1. Следующим шагом стоит построить и запустить проект в IDE. Откройте Qt
     Creator, и в нем откройте наш проект. Необходимо указать на файл
     `CMakeLists.txt`, находящийся в директории `code`. В эксплорере проекта
     (панель слева) должен появиться как минимум проект-пример, структуру
     которого стоит изучить. Также стоит запустить модуль с тестами, и
     убедиться, что они проходят.

Далее можно приступать к выполнению собственно лабораторной работы.

### Выполнение лабораторной

  1. Первым шагом создайте в своей директории структуру, аналогичную той, что
     показана в проекте-примере. У вас должны появиться три директории:
     `include`, `src` и `test`.
  1. Затем перенесите файл `CMakeLists.txt` и модифицируйте его под свой проект.
     По факту нужно лишь обновить строки с объявлением переменных `libname` и
     `testname`. Просьба следовать соглашениям, и называть модули согласно
     следующему шаблону: `surname-name-projectname-library` и
     `surname-name-projectname-test`.
  1. Затем разработайте интерфейс класса (h-файл), и поместите его в папку
     `include`. На самом деле это самая ответственная часть настоящей
     лабораторной работы. __Необходимо придумать простой, понятный и удобный
     интерфейс для своего класса. Возможно потребуется сделать несколько
     итераций, потратьте на это время.__
     - Постарайтесь избегать лишних зависимостей в своем заголовочном файле.
     - Также желательно предоставлять минималистичный публичный интерфейс
       (секция `public`), позволяющий решить задачу, а все остальное поместить в
       `protected` и `private` секции класса.
  1. Затем необходимо реализовать ваш класс и положить исходный код в директорию
     `src`. Просьба дать файлу расширение `cxx`  — это некоторое соглашение в
     нашем проекте, для cxx-файлов автоматически считается покрытие тестами.
  1. После этого следует покрыть API вашего класса тестами. Нужно протестировать
     каждый публичный метод, на корректный и некорректный ввод. Когда вы пошлете
     пулл реквест, Travis и система Coveralls сообщат покрытие для вашего
     модуля. По результатам покрытие должно быть 100%, если у вас получилось
     меньше, нужно добавить тестов.
     - __Важное замечание:__ во время написания тестов вам может показаться, что
       API вашего класса неудобен и его можно улучшить. В таком случае нужно
       вернуться и переделать API.
  1. Когда все будет готово, нужно снова прислать пулл-реквест. Как и всегда,
     первым делом стоит добиться "зеленого" билда от Travis CI, после чего
     получить одобрение от двух сокурсников в виде `+1`.
     - Скорее всего будут замечания от скрипта, проверяющего стиль кодирования.
       Замечания нужно исправить и сделать коммиты в ту же ветку, пулл реквест
       обновится автоматически.

<!-- LINKS -->

[git-pull]: https://groups.google.com/d/msg/devtools-course/V8rtlLrCXc4/k7vx6BxnqR4J
