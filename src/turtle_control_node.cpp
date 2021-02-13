/* turtle_control_node.cpp */



#include "ros/ros.h"                    // allgemeiner Header für ROS
#include <geometry_msgs/Twist.h>        // Nachricht zum Verschicken von Geschwindigkeitsbefehlen
#include <turtlesim/Spawn.h>            // Spawn-Service
#include <turtlesim/Pose.h>             // Nachricht für die Pose der Schildkröte
#include <turtlesim/SetPen.h>           // Service zum Ändern der Spurfarbe


void callbackPose(const turtlesim::Pose& msg)
{
  // Achtung Zusatzaufgabe: 
  // FÜLLEN SIE HIER DAS TEMPLATE MIT EIGENEM CODE


}


int main(int argc, char **argv)
{
  if(argc<2)
  {
    std::cout << "Too few parameters.\nExpected call: rosrun turtle_control turtle_control_node <turtlename>" << std::endl;
    return -1;
  }

  // Name des eigenen Knotens
  std::string node_name(argv[1]);
  ROS_INFO_STREAM("Neuer Knoten: " << node_name);

  ros::init(argc, argv, node_name);
  ros::NodeHandle nh;


  std::string vel_topic(node_name + "/cmd_vel");
  std::string pen_topic(node_name + "/set_pen");
  std::string pose_topic(node_name + "/pose");
  std::string spawn_topic("spawn");


   ros::ServiceClient spawn_client= nh.serviceClient<turtlesim::Spawn>(spawn_topic); 
   ros::ServiceClient pen_client  = nh.serviceClient<turtlesim::SetPen>(pen_topic);   

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
  ros::Subscriber pose_sub = nh.subscribe(pose_topic, 1, callbackPose);


  /*
   * Implementieren Sie hier das Versenden von Nachrichten
   * zur Steuerung der Schildkröte
   */
   ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>(vel_topic, 1); 
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

