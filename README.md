# Face_Detection_OpenCV_Cpp
Face Detection using Haar Cascades


all steps needed to recompile the project from source code are available bellow.


this project is coded in C++, tested and running perfectly using :

- Microsoft Windows 10

- Microsoft Visual Studio 2017

- OpenCV 3.4.5


let me know if you experience issues trying to compile and run this project on different environments and you need help.


you could import the project directly after extracting the .ZIP file the RUN it


or


setup steps from scratch :

1- install Visual Studio 2017 using Visual Studio Installer and choose the option that makes it ready for C++ development

2- install OpenCV 3.4.5 at c:\opencv

3- launch Visual Studio 2017 and choose New Project/Solution, under Visual C++, select Windows Console Application

4- configure your just created project to be ready to use previously installed OpenCV libraries :

    a- set your build config to Debug and Platform to x64 from toolbar
    
    b- edit your project properties to :
    
        i- general => target platform version = "10"
        
        ii- c/c++ => general => additional include directories = "C:\opencv\build\include"
        
        iii- linker => general => additional library directories = "C:\opencv\build\x64\vc15\lib"
        
        iv- linker => input => additional dependencies = "opencv_world345d.lib"
        
5- copy "haarcascade_frontalface_alt.xml" to project directory where your "<project_name>.cpp" resides

6- copy and paste "Face_Detection_OpenCV_Cpp.cpp" source code content to your "<project_name>.cpp"

7- save all changes, Build your Solution and Start Debugging.
