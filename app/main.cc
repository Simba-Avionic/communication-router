#include "application/application_factory.h"
#include "app/router.h"

int main(int argc, char const *argv[])
{
    simba::core::ApplicationFactory<simba::router::Router>::Start(argc,argv);
    return 0;
}
