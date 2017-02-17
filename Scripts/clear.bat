rmdir /S /Q %~dp0..\NCommon\release
rmdir /S /Q %~dp0..\NCommon\debug
rmdir /S /Q %~dp0..\NCommon\build_
rmdir /S /Q %~dp0..\Example\build_
rmdir /S /Q %~dp0..\Example\release
rmdir /S /Q %~dp0..\Example\debug
rmdir /S /Q %~dp0..\3rdparty\pinyin\build_
rmdir /S /Q %~dp0..\3rdparty\pinyin\release
rmdir /S /Q %~dp0..\3rdparty\pinyin\debug
del /Q %~dp0..\Makefile*
del /Q %~dp0..\NCommon\Makefile*
del /Q %~dp0..\3rdparty\pinyin\Makefile*
del /Q %~dp0..\Example\Makefile*
