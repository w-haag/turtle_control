/* turtle_control_node.cpp */



#include "ros/ros.h"                    // allgemeiner Header für ROS
#include <geometry_msgs/Twist.h>        // Nachricht zum Verschicken von Geschwindigkeitsbefehlen
#include <turtlesim/Spawn.h>            // Spawn Service
#include <turtlesim/Pose.h>             // Nachricht für die Pose der Schildkröte
#include <turtlesim/SetPen.h>


void callbackPose(const turtlesim::Pose& msg)
{
  // Achtung Zusatzaufgabe: 
  // FÜLLEN SIE HIER DAS TEMPLATE MIT EIGENEM CODE


}


int main(int argc, char **argv)
{
  if(argc<2)
  {
    std::cout << "Too less parameters. Expected: " << argv[0] << " <turtlename>" << std::endl;
    return -1;
  }


  /**
   * Name des eigenen Knotens
   */
  char node[64];
  sprintf(node, "%s%s", argv[1], "_node");
  printf("Neuer Knoten: %s\n", node);

  ros::init(argc, argv, node);
  ros::NodeHandle n;


  /**
   * Name des publishers
   */
  char pubname[64];
  sprintf(pubname, "%s/%s", argv[1], "cmd_vel");
  printf("Publisher: %s\n", pubname);


  char penname[64]; 
  sprintf(penname, "%s/%s", argv[1], "set_pen"); 

   ros::ServiceClient spawn_client= n.serviceClient<turtlesim::Spawn>("spawn"); 
   ros::ServiceClient pen_client  = n.serviceClient<turtlesim::SetPen>(penname);   
/*

  /*
   * Implementieren Sie hier den Aufruf des Dienstes spawn. Hierzu müssen
   * Sie die Variable srv mit den notwendigen Informationen befüllen. 
   * Die Definition des Service Spawn haben Sie in der Vorlesung bereits kennen
   * gelernt. Alternativ dazu können Sie hier auch nochmal nachschlagen: 
   * http://docs.ros.org/melodic/api/turtlesim/html/srv/Spawn.html
   *
   * Senden Sie einen Service-Call über den Service spawn_client ab
   * Beachten Sie, dass der name der Schildkröte mit argv[1] gesetzt wird, so dass
   * jede Schildkröte im Netzwerk nur einmal vorkommt.
   */
   turtlesim::Spawn srv;
   // FÜLLEN SIE HIER DAS TEMPLATE MIT EIGENEM CODE










   /* Für Schnelle:
    * 1) Ändern Sie die Farbe der Schildkröte in abhängigkeit ihrer x, y Position.
    *    Seien Sie kreativ!
    * 2) Lassen Sie die Schildkröte ein Rechteck abfahren.
    *
    */
  char posename[64]; 
  sprintf(posename, "%s/%s", argv[1], "pose");
  ros::Subscriber pose_sub = n.subscribe(posename, 1, callbackPose);


  /**
   * Implementieren Sie hier das Versenden von Nachrichten
   * zur Steuerung der Schildkröte
   */
   ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>(pubname, 1); 
   ros::Rate r(10); 



   while(ros::ok())
   {
      /*
       * Erstellen Sie an dieser Stelle eine Nachricht vom Typ geometry_msgs::Twist
       * Wie die Nachricht definiert ist wissen Sie bereits aus einem vorangeganenen
       * Versuch mit Turtlesim. Außerdem können Sie hier nochmal nachsehen: 
       * http://docs.ros.org/melodic/api/geometry_msgs/html/msg/Twist.html
       *
       * Füllen Sie den Inhalt der Nachricht, so dass die Schildkröte eine Kreis-
       * bahn fährt. Schicken Sie die Nachricht im Anschluss mittels des Publishers
       * vel_pub
       */
      geometry_msgs::Twist msg; 
      // FÜLLEN SIE HIER DAS TEMPLATE MIT EIGENEM CODE









      ros::spinOnce();  
      r.sleep(); 
   }


  return 0;
}

