# October 2

* Task- learning about circuits, namely capacitors, current, and transistors
* Introduction to circuits
	* Beginning with three components we didn’t really have to cover with the arduinos because they were prefabricated pieces
		* Capacitors- act like passive batteries 
			* Two plates separated from each other forever by a dielectric when one plate becomes charged one way the other is charged opposite and the charge is stored until a change is made in the circuit
			* Gauged for specific storing capacity(capacitance(in farads)) and voltage
		* Many different types that are particularly good in certain areas 
			1. Ceramic- low Capacity but work reliably at high voltage and low leakage
			2. Electrolytics- High capacity and operate at high voltages but are polarized and more than other types
			3. Supercapacitors- High capacity and retention but cannot work at high voltages 
		* Capacitors work the exact inverse as resistors in parallel and series
			* When put in series they dilute each other's respective storing capacity but increase voltage tolerance 
			* When in parallel the total capacity is the sum of the parts but the voltage tolerance is equal to that of the lowest one, which is not aided by the others in the circuit
		* In terms of usage they are used to compensate for unwanted changes in voltage from the power supply. If the voltage supply drops below what is needed by the circuit the excess charge in the capacitor gets used. When the voltage is more than needed by the system it can be stored in the capacitor until is has reached its voltage capacity, at which point any excess overflows to the ground
		*	Capacitors are essential to compensate for inconsistencies
	* AC- alternating current
	* DC- direct current
		* Two main ways that current is carried that runs the electronics of today
		* DC is straightforward- the power is sent from the power supply to the electronic as a constant stream of positive current. 
			* Problem is this requires a lot of power and creates a lot of heat to keep sending the same current so sending power long distance is difficult
		*	AC is more complicated- the power level oscillates moving from max(+C) to minimum(-C) along a sine curve(usually). This prevents the buildup that results in heat in DC and allows AC to be sent over longer distances
			* Problem is home electronics don’t want an the negative charges, they want DC so it has to be converted
	* Transistors- can act is either a passive switch or amplify a signal this is their usual use
		* Transistors before current have a section with too much negativity and a section with too much and when current is sent through the more negative moves to the less negative
		* Depending on the setup of the transistor as it relates to the charges of the power being sent it can either prevent electricity flow(reverse biased) or can push the negative towards the positive(stimulating flow)
		* When two power sources are put to a single transistor in a certain setup(one forward biased diode, and one that has both a forward and a revered bias), the power from the first source amplifies the power from the second

* Next Up: No clue but probably using capcitors 
