Regularfile - код идентификации для обычного файла. <br> Он объединяет самые различные виды файлов, такие как текст, изображения, бинарные файлы, библиотеки и т.д. 
<li>Создание: touch Regularfile.txt (просмотр того, что он создан ls -ld Regularfile.txt)
<li>Запись: vi Regularfile.txt (i редактор перейдёт в режим ввода текста. Можно удалять целые строки командой dd.<br> Для выхода введите Esc и Команда :wq сначала сохраняет файл со сделанными изменениями, а затем выходит из редактора vi. )
<li>Чтение: cat Regularfile.txt
<li>Удаление: rm Regularfile.txt (с помощью ls -ld Regularfile.txt проверяем, что файла нет)

![image](https://user-images.githubusercontent.com/40539112/151754446-99f2fb09-dda7-4d35-923d-e0e45f51e997.png)
![image](https://user-images.githubusercontent.com/40539112/151754997-71c88688-e57a-42a3-af85-d7494421f6ea.png)

  “d” directory директория (каталог) 
<li>Создание: mkdir Directoria (просмотр того, что она создан ls -ld Directoria)
<li>Запись: Чтобы добавить файл в директорию нужно перейти в нее (cd Directoria) и создать файл (touch Regularfile.txt) или touch /home/user/Перезаписать/Regularfile
<li>Чтение: С помощью команды ls можно посмотреть, что находится в директории
<li>Переименовать: mv Directoria ~/Перезаписать
<li>Удаление: Чтобы удалить директорию надо вернуться в папку, в которой она была создана (cd ..). Команда rmdir Directoria. Однако если нужно удалить папку, которой содержатся файлы rm -r  Directoria/ (просмотр того, что она удалена ls -ld Directoria)
