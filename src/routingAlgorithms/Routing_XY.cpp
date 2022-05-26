#include "Routing_XY.h"

RoutingAlgorithmsRegister Routing_XY::routingAlgorithmsRegister("XY", getInstance());

Routing_XY * Routing_XY::routing_XY = 0;

Routing_XY * Routing_XY::getInstance() {
	if ( routing_XY == 0 )
		routing_XY = new Routing_XY();
    
	return routing_XY;
}

vector<int> Routing_XY::route(Router * router, const RouteData & routeData)
{
    Coord current = id2Coord(routeData.current_id);
    Coord destination = id2Coord(routeData.dst_id);
    vector <int> directions;
    
    if (destination.x > current.x)
    {
    	if(find(GlobalParams::HubLocations.begin(), GlobalParams::HubLocations.end(), routeData.current_id + 1) != GlobalParams::HubLocations.end())
    		directions.push_back(DIRECTION_HUB);
    	else directions.push_back(DIRECTION_EAST);
    }
    else if (destination.x < current.x)
    {
    	if(find(GlobalParams::HubLocations.begin(), GlobalParams::HubLocations.end(), routeData.current_id - 1) != GlobalParams::HubLocations.end())
    		directions.push_back(DIRECTION_HUB);
        else directions.push_back(DIRECTION_WEST);
    }
    else if (destination.y > current.y)
    {
    	if(find(GlobalParams::HubLocations.begin(), GlobalParams::HubLocations.end(), routeData.current_id + GlobalParams::mesh_dim_x) != GlobalParams::HubLocations.end())
    		directions.push_back(DIRECTION_HUB);
        else directions.push_back(DIRECTION_SOUTH);
    }
    else
    {
    	if(find(GlobalParams::HubLocations.begin(), GlobalParams::HubLocations.end(), routeData.current_id - GlobalParams::mesh_dim_x) != GlobalParams::HubLocations.end())
    		directions.push_back(DIRECTION_HUB);
        else directions.push_back(DIRECTION_NORTH);
    }
    return directions;
   } 
