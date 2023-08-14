public List<Passenger> getAllPassenger()
        {
        List<Passenger> result = new Vector<Passenger>();

        Passenger p1 = new Passenger();
        p1.setBookingCode("GYIKJN")
        p1.setIdentityNumber("18271097020001")
        p1.setPassengerName("Andi Muliadi")
        result.add(p1);

        Passenger p2 = new Passenger();
        p2.setBookingCode("ZNJGQK")
        p2.setIdentityNumber("79812539720001")
        p2.setPassengerName("Budi Dirgantara")
        result.add(p2);

        Passenger p3 = new Passenger();
        p3.setBookingCode("VFZWAQ")
        p3.setIdentityNumber("56783128960002")
        p3.setPassengerName("Wisnu Dwi Perdana")
        result.add(p3);

        return result;
        }