/**
 * Copyright (C) 2013 TomTom International B.V.
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
package org.genivi.trafficinfo.tpeg.tec.event;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.eclipse.emf.common.util.Enumerator;

/**
 * <!-- begin-user-doc -->
 * A representation of the literals of the enumeration '<em><b>People On Roadway</b></em>',
 * and utility methods for working with them.
 * <!-- end-user-doc -->
 * @see org.genivi.trafficinfo.tpeg.tec.event.EventPackage#getPeopleOnRoadway()
 * @model
 * @generated
 */
public enum PeopleOnRoadway implements Enumerator {
	/**
	 * The '<em><b>CHILDREN ON ROADWAY</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #CHILDREN_ON_ROADWAY_VALUE
	 * @generated
	 * @ordered
	 */
	CHILDREN_ON_ROADWAY(0, "CHILDREN_ON_ROADWAY", "CHILDREN_ON_ROADWAY"),

	/**
	 * The '<em><b>CYCLISTS ON ROADWAY</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #CYCLISTS_ON_ROADWAY_VALUE
	 * @generated
	 * @ordered
	 */
	CYCLISTS_ON_ROADWAY(2, "CYCLISTS_ON_ROADWAY", "CYCLISTS_ON_ROADWAY"),

	/**
	 * The '<em><b>MOTOR CYCLIST ON ROADWAY</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #MOTOR_CYCLIST_ON_ROADWAY_VALUE
	 * @generated
	 * @ordered
	 */
	MOTOR_CYCLIST_ON_ROADWAY(3, "MOTOR_CYCLIST_ON_ROADWAY", "MOTOR_CYCLIST_ON_ROADWAY");

	/**
	 * The '<em><b>CHILDREN ON ROADWAY</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>CHILDREN ON ROADWAY</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #CHILDREN_ON_ROADWAY
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int CHILDREN_ON_ROADWAY_VALUE = 0;

	/**
	 * The '<em><b>CYCLISTS ON ROADWAY</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>CYCLISTS ON ROADWAY</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #CYCLISTS_ON_ROADWAY
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int CYCLISTS_ON_ROADWAY_VALUE = 2;

	/**
	 * The '<em><b>MOTOR CYCLIST ON ROADWAY</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>MOTOR CYCLIST ON ROADWAY</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #MOTOR_CYCLIST_ON_ROADWAY
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int MOTOR_CYCLIST_ON_ROADWAY_VALUE = 3;

	/**
	 * An array of all the '<em><b>People On Roadway</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final PeopleOnRoadway[] VALUES_ARRAY =
		new PeopleOnRoadway[] {
			CHILDREN_ON_ROADWAY,
			CYCLISTS_ON_ROADWAY,
			MOTOR_CYCLIST_ON_ROADWAY,
		};

	/**
	 * A public read-only list of all the '<em><b>People On Roadway</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<PeopleOnRoadway> VALUES = Collections.unmodifiableList(Arrays.asList(VALUES_ARRAY));

	/**
	 * Returns the '<em><b>People On Roadway</b></em>' literal with the specified literal value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static PeopleOnRoadway get(String literal) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			PeopleOnRoadway result = VALUES_ARRAY[i];
			if (result.toString().equals(literal)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>People On Roadway</b></em>' literal with the specified name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static PeopleOnRoadway getByName(String name) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			PeopleOnRoadway result = VALUES_ARRAY[i];
			if (result.getName().equals(name)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>People On Roadway</b></em>' literal with the specified integer value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static PeopleOnRoadway get(int value) {
		switch (value) {
			case CHILDREN_ON_ROADWAY_VALUE: return CHILDREN_ON_ROADWAY;
			case CYCLISTS_ON_ROADWAY_VALUE: return CYCLISTS_ON_ROADWAY;
			case MOTOR_CYCLIST_ON_ROADWAY_VALUE: return MOTOR_CYCLIST_ON_ROADWAY;
		}
		return null;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private final int value;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private final String name;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private final String literal;

	/**
	 * Only this class can construct instances.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private PeopleOnRoadway(int value, String name, String literal) {
		this.value = value;
		this.name = name;
		this.literal = literal;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getValue() {
	  return value;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getName() {
	  return name;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getLiteral() {
	  return literal;
	}

	/**
	 * Returns the literal value of the enumerator, which is its string representation.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String toString() {
		return literal;
	}
	
} //PeopleOnRoadway
