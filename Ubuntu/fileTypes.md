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

![image](https://user-images.githubusercontent.com/40539112/151755836-590f6c2e-809d-488e-bbce-4c3129f4e74d.png)

“l” symlink символическая ссылка. С помощью символических ссылок администратор может присвоить одному файлу или директории несколько идентичностей. Символическая ссылка является указателем на оригинальный файл. Существует два типа символических ссылок: - жесткие ссылки; - мягкие ссылки.
Различие между твердыми и мягкими ссылками в том, что мягкие ссылки ссылаются на имя файла, в то время как жесткие ссылки прямо ссылаются на оригинальный файл. Кроме того, жесткие ссылки не работают с файлами, расположенными на других разделах или файловых системах. 
<li>Создание: echo "some text" > file1 ln -s file1 file2 cat file2 (soft просмотр того, что файл 2 ссылается на файл 1). Просмотр того, что ссылка создана ls -ld file2.
<li>Запись: Можно записывать в 1й файл, текст добавтся и во 2й (echo "more text" >>file2)

<li>Чтение: cat file2
<li>Удаление: unlink file1. Просмотр того, что ссылка удалилась ls -ld file1
  
![image](https://user-images.githubusercontent.com/40539112/151756594-d2a8dc42-04e0-400c-9b4a-9080b70a6065.png)

“s” unix sockets файл локального сокета. Сокеты локального домена используются для обмена данными между процессами. В основном они используются такими службами, как X windows, syslog и т.д. 
<li>Создание: mkfifo socket.sock (можно не использовать)
<li>Запись: nc -lU socket.sock (сервер)
<li>Чтение: nc -U socket.sock (клиент)
<li>Удаление: системной функции unlink или командой rm socket.sock
  
![image](https://user-images.githubusercontent.com/40539112/151758052-671b7f9d-43a5-44dd-91e7-fb673c4568f5.png)

  “p” pipe именованный канал Как и локальные сокеты, именованные каналы позволяют осуществлять обмен данными между локальными процессами.
<li>Создание: mkfifo pkanal и просмотр ls -ld pkanal
<li>Запись: echo "запись" > pkanal
<li>Чтение: во втором окне cat pkanal
<li>Удаление: rm pkanal

![image](https://user-images.githubusercontent.com/40539112/151757565-3896e3bb-86d6-4d35-bd4f-93a30b9791f4.png)
  
  “b” block device файл блочного устройства (sudo su)
<li>Создание: sudo mknod blockd b 5 100
<li>Запись: echo tekst > blockd
<li>bash: blockd: Отказано в доступе
bs=100M(чисто мегабайт) count=5(количество итераций)
<li>Удаление: rm block	d
  
![image](https://user-images.githubusercontent.com/40539112/151758430-ff9bde42-d4d1-4b7b-b612-e48dec1418f1.png)
  
 “c” chat device файл символьного устройства 
<li>Создание: Надо зайти от администратора mknod charv c 5 100
<li>bs=100M(чисто мегабайт) count=5(количество итераций)

<li>Удаление: sudo rm charv
<br>А символьные файлы устройств используются для небуферизованного обмена данными. Большинство устройств способно принимать и отправлять данные либо блоками (блочные устройства), либо сплошным потоком байтов (символьные устройства), но некоторые (такие как жёсткий диск) сочетают в себе обе эти возможности. Работа с первым типом устройств возможна либо через блочные, либо через символьные файлы, а вот с последним типом — подходят и те, и другие. 
  
![image](https://user-images.githubusercontent.com/40539112/151758655-98e351a3-08f8-4c27-8060-f42fe2c9ccbc.png)
  
 Уточнение про жесткую ссылку
<li>Создали папку: mkdir test && cd test
<li>Создали файл: echo "some text" > source
<li>Создали жесткую ссылку: ln source hardlink

Добавили еще файлы для мусора
<li>echo "some text" > file1
<li>echo "some text" > file2
<li>echo "some text" > file3
<li>echo "some text" > abc

<br>В свойствах stat hardlink взяли Inode: 397128
<br>Поиск по иноду find -inum 397128
<br>Нашли файл


СКРИПТ

<br>WHERE_TO_LOOK_FOR=$1
<br>FILE_PATH=$2
<br>FOR_WHICH_FILE_YOU_LOOK_LINK=$3
<br>for dirname in $(find -L $1 -samefile $2)
<br>do
<br>ls -l "$dirname"
<br>ls -i1 "$dirname"
<br>echo "Вы ищете хард ссылку для файла $2/$3. Его инод: $(stat -c %i $2/$3)"
<br>echo "Все файлы с таким же инодом:"

<br>find -inum $(stat -c %i $2/$3)

<br>done

<br>Для запуска bash script1.sh test /home/user/test source
  
  <h2></h2>
