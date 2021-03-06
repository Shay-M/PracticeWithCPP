#pragma once
#include "Customer.h"

typedef struct Node
{
	Customer *NowCustomer;
	Customer **NextCustomer;
};