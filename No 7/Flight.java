//Flight.Java
package Core;

import java.util.AbstractList;
import java.util.Date;
import java.util.List;
import java.util.Vector;

public class FlightData {
    public class PlaneData
    {
        public String planeNo;
        public String planeName;
        public int capacity;
    }

    public PlaneData plane = new PlaneData();
    public String flightNo;
    public String destinationAirport;
    public String departureAirport;
    public Date flightDate;
    public String arrivalTime;
    public String departTime;
    public List<Passenger> passenger = new Vector<Passenger>();
}