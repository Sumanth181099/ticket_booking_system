#include "unity.h"
#include <train_structs.h>
#define PROJECT_NAME    "ticket_booking_system"

/* Prototypes for all the test functions */
void test_update_train_schedule(void);
void test_disp_train(void);
void test_disp_cust(void);
void test_reservation(void);
void test_disp_train_details(void);
void test_cust_details_entry(void);
void test_total_cost(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_update_train_schedule);
  RUN_TEST(test_disp_train);
  RUN_TEST(test_disp_cust);
  RUN_TEST(test_reservation);
  RUN_TEST(test_disp_train_details);
  RUN_TEST(test_cust_details_entry);
  RUN_TEST(test_total_cost);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_update_train_schedule(void) {
 
}
void test_disp_train(void) {
 
}
void test_disp_cust(void) {
  
}

void test_reservation(void) {

}

void test_disp_train_details(void) {

}
void test_cust_details_entry(void) {
  
}
void test_total_cost(void) {
  TEST_ASSERT_EQUAL(0, total_cost(0, 1000));
}
