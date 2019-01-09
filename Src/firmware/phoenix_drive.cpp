/**
 * phoenix_drive.cpp
 **/
#include "phoenix_drive.h"
#include "phoenix_params.h"

/**
 * matrice cinematica robot a 3 assi
 * da velocita motori => forze su robot
 **/
static double kmatrix[NUM_JOINTS][NUM_JOINTS] =
{
  {0.33, -0.33, 0.57},
  {0.33, -0.33, -0.57},   //sbagliata
  {0.33, 0.66, 0}
};

/**
 * matrice inversa cinematica robot a 3 assi
 * da forze su robot => velocita motori
 **/
static double ikmatrix[NUM_JOINTS][NUM_JOINTS] =
{
  {0.33, -0.33, 0.57},
  {0.33, -0.33, -0.57},   
  {0.33, 0.66, 0}
};

/**
 * inizializza d (PhoenixDrive) azzerando le velocita desiderate
 * e regolate.
 * In oltre  imposta d->joints = joint_array
 **/
void PhoenixDrive_init(PhoenixDrive* d, PhoenixJoint* joint_array) {
  d->vel_x_desiderata = 0;
  d->vel_y_desiderata = 0;
  d->joints = joint_array;
}

/**
 * imposta le velocita desiderate di d, in funzione dei parametri
 * x, y e r
 */
void PhoenixDrive_setSpeed(PhoenixDrive* d, double x, double y, double r) {
  d->vel_x_desiderata = x;
  d->vel_y_desiderata = y;
  d->rot_desiderata = r;
}

/**
 * Calcola ed assegna le velocita per 
 * ogni Joint presente in d->joints 
 **/
void PhoenixDrive_handle(PhoenixDrive* d) {
  double comp_vector[3] = {d->vel_x_desiderata, d->vel_y_desiderata, d->rot_desiderata};
  double speed = 0;
  for(int a=0;a<NUM_JOINTS;a++)
  {
    for(int b=0;b<NUM_JOINTS;b++)
    {
      speed+=kmatrix[a][b]*comp_vector[b];
    }
  }
}

/**
 * Azzera i valori di velocita desiderate in d (PhoenixDrive)
 * e rilancia PhoenixDrive_handle
 **/
void PhoenixDrive_reset(PhoenixDrive* d) {
  d->vel_x_desiderata = 0;
  d->vel_y_desiderata = 0;
  PhoenixDrive_handle;
}
