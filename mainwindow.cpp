#include "mainwindow.h"
#include <QDebug>
#include <QString>

Window::~Window()
{
	makeCurrent(); // TODO: learn
	teardownGL();
}

///////////////////////////OpenGL Events////////////////////////

void Window::initializeGL()
{
	// Initialize OpneGL Backend
	initializeOpenGLFunctions();
	printContextInformation();

	// Set global information
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Window::resizeGL(int width, int height) 
{
	// currently not handling width/height changes
	(void)width;
	(void)height;
}

void Window::paintGL()
{
	// Clear
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::teardownGL()
{
	// currently we have no data to teardown
}

///////////////////////////Private Helpers///////////////////////

void Window::printContextInformation()
{
	QString glType;
	QString glVersion;
	QString glProfile;

	// Get version information
	glType = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
	glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));

	//Gt profile information
#define CASE(c) case QSurfaceFormat::c: glProfile = #c; break
	switch (format().profile())
	{
		CASE(NoProfile);
		CASE(CoreProfile);
		CASE(CompatibilityProfile);
	}
#undef CASE

	// qPrintable() will print our QString w/o quotes around it
	qDebug() << qPrintable(glType) << qPrintable(glVersion) << "(" << qPrintable(glProfile) << ")";
}