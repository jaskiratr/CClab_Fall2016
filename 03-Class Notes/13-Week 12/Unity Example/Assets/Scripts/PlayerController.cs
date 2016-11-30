using UnityEngine;
using System.Collections;
using UnityEngine.UI;

// To check more info about codes you need, CMD+'(MAC) or CONTROL+' (PC)  to search the Unity API

public class PlayerController : MonoBehaviour {

	public float speed;
	public Text countText;
	public Text winText;
	private Rigidbody rb;

	public int count;

	// Use this for initialization
	void Start () {
		rb = GetComponent<Rigidbody>();
		count = 0;
		SetCountText ();
		winText.text = "";
	}
	
	// Update is called once per frame (called before frame is rendered)
	void Update () {
	}

	// Fixed update is called just before performing any physics calculations.
	// We're applying forces to move our ball, so a lot of code goes here.

	void FixedUpdate() { 
		// use inputs to apply force to our sphere
		float moveHorizontal = Input.GetAxis ("Horizontal");
		float moveVertical = Input.GetAxis ("Vertical");

		Vector3 movement = new Vector3 (moveHorizontal, 0.0f, moveVertical);

		rb.AddForce (movement * speed);
	}

	/* The physics engine doesn't allow two collider volumes to overlap.
	When the physics engine detects that any two or more colliders will overlap that 
	frame the physics engine will look at the objects and analyse their speed and rotation and shape
	and calculate a collision. One of the major factors in this calculation is whether the colliders are static
	or dynamic. When calculating a collision the static geometry will not be affected by the collision. 
	But the dynamic objects will be. The physics engine can however allow the penetration or overlap of collider volumes.
	When it does this the physics engine still calculates the collider volumes and keeps track of the collider overlap.
	But it doesn't physically act on the overlapping objects, it doesn't cause a collision. */
	void OnTriggerEnter(Collider other) {
		if (other.gameObject.CompareTag ( "Pick Up")) {
			other.gameObject.SetActive (false);
			count = count + 1;
			SetCountText ();
		}
	}

	// shift+alt to set both anchor and pivot point
	void SetCountText () {
		countText.text = "Count: " + count.ToString ();
		if (count >= 13) {
			winText.text = "You Win!";
		}
	}
}