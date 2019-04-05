import { Component, OnInit } from '@angular/core';
import {GamepadService} from '../gamepad.service';

@Component({
  selector: 'app-gamepad',
  templateUrl: './gamepad.component.html',
  styleUrls: ['./gamepad.component.css']
})
export class GamepadComponent implements OnInit {

  constructor(private g: GamepadService) { }
  ngOnInit() {
    console.log("Hello");
    this.g.getJoystick();
  }

}
