#include <iostream>
#include <QGuiApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	
	// set OpenGL version information
	QSurfaceFormat format;
	format.setRenderableType(QSurfaceFormat::OpenGL);
	format.setProfile(QSurfaceFormat::CoreProfile);
	format.setVersion(3, 3);

	// set the window
	Window window;
	window.setFormat(format);
	window.resize(QSize(800, 600));
	window.show();

return app.exec();
}
