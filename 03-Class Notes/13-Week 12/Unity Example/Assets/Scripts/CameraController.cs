using UnityEngine;
using System.Collections;

public class CameraController : MonoBehaviour {

	public GameObject player;

	private Vector3 offset;

	void Start ()
	{
		offset = transform.position - player.transform.position;
	}

	// For follow cameras, procedural animation and gathering last known states, it's best to use LateUpdate
	// LateUpdate runs after all items have been processed in update
	void LateUpdate ()
	{
		transform.position = player.transform.position + offset;
	}
}