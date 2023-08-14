class Processor {
  private double ClockSpeed;
  private double Cores;

  public double getClockSpeed() {
    return ClockSpeed;
  }
  public void setClockSpeed(double ClockSpeed) {
    this.ClockSpeed = ClockSpeed;
  }
  public double getCores() {
    return Cores;
  }
  public void setCores(double Cores) {
    this.Cores = Cores;
  }
}

class Car {
  //  Delegation Object Processor
  private Processor Processor;
  private String brand;
  private String model;

  public String getName() {
    return brand + " " + model + " (" + getCores() + "Cores)";
  }
  public String getModel() {
    return model;
  }
  public void setModel(String model) {
    this.model = model;
  }
  public String getBrand() {
    return brand;
  }
  public void setBrand(String brand) {
    this.brand = brand;
  }

  // Delegated Methods
  public double getClockSpeed() {
    return Processor.getClockSpeed();
  }
  public void setClockSpeed(double ClockSpeed) {
    Processor.setClockSpeed(ClockSpeed);
  }
  public double getCores() {
    return Processor.getCores();
  }
  public void setCores(double Cores) {
    Processor.setCores(Cores);
  }
}
