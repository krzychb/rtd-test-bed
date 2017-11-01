/**
 * \file manual.c
 */

typedef struct Object Object;   //!< Object type
typedef struct Vehicle Vehicle; //!< Vehicle type
typedef struct Car Car;         //!< Car type
typedef struct Truck Truck;     //!< Truck type

/*!
 * Base object class.
 * Ref vehicleStart(), objRef(), objUnref(), SomeDataCallback() .
 */
struct Object
{
  int ref;    //!< \private Reference count.
};


/*!
 * Increments object reference count by one.
 * \public \memberof Object
 */
static Object * objRef(Object *obj);


/*!
 * Decrements object reference count by one.
 * \public \memberof Object
 */
static Object * objUnref(Object *obj);


/*!
 * Vehicle class.
 * \extends Object
 */
struct Vehicle
{
  Object base;    //!< \protected Base class.
};


/*!
 * Starts the vehicle.
 * \public \memberof Vehicle
 */
void vehicleStart(Vehicle *obj);


/*!
 * Stops the vehicle.
 * \public \memberof Vehicle
 */
void vehicleStop(Vehicle *obj);


/*!
 * Car class.
 * \extends Vehicle
 */
struct Car
{
  Vehicle base;    //!< \protected Base class.
};


/*!
 * Main function.
 *
 * Ref vehicleStart(), objRef(), objUnref().
 * \public \memberof Car
 */
int main(void)
{
  Car c;
  vehicleStart((Vehicle*) &c);
}


/*!
 * Truck class.
 * \extends Vehicle
 */
struct Truck
{
  Vehicle base;    //!< \protected Base class.
};


/**
 * @brief           Register A2DP sink data output function; For now the output is PCM data stream decoded
 *                  from SBC format. This function should be called only after esp_bluedroid_enable() 
 *                  completes successfully
 *                  
 * @param[in]       callback: A2DP data callback function
 *
 * @return
 *                  - ESP_OK: success
 *                  - ESP_INVALID_STATE: if bluetooth stack is not yet enabled
 *                  - ESP_FAIL: if callback is a NULL function pointer
 * \memberof Vehicle
 *
 */
void SomeDataCallback(data_cb_t callback);