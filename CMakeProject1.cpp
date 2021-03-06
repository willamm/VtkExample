// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"

using namespace std;

int main(int argc, char** argv)
{
	QVTKApplication app(argc, argv);
	QMainWindow window;
	
	// Add VTK stuff here
	// Use QVTKOpenGLWidget instead of QVTKWidget
	QVTKOpenGLWidget* qvtkwidget = new QVTKOpenGLWidget();
	vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
	qvtkwidget->SetRenderWindow(renderWindow.Get());

	// Sphere
	vtkNew<vtkSphereSource> sphereSource;
	sphereSource->Update();
	vtkNew<vtkPolyDataMapper> sphereMapper;
	sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
	vtkNew<vtkActor> sphereActor;
	sphereActor->SetMapper(sphereMapper.Get());

	// VTK Renderer
	vtkNew<vtkRenderer> renderer;
	renderer->AddActor(sphereActor.Get());

	qvtkwidget->GetRenderWindow()->AddRenderer(renderer.Get());

	window.setCentralWidget(qvtkwidget);

	window.show();
	return app.exec();
}
