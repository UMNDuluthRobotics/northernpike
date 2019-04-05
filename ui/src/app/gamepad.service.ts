import { Injectable } from '@angular/core';
import {fromEvent} from 'rxjs';
import {map} from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})
export class GamepadService {

  constructor() {console.log('Test');
    const source = document.addEventListener(document, fromEvent, 'gamepadconnected');
    //const source = fromEvent (document, 'gamepadconnected');
    const example = source.pipe(map(event => 'Event time: ${event.timeStamp}'));
    const subscribe = example.subscribe(val => console.log(val));
  }

  getJoystick() {
    const source = fromEvent (document, 'gamepadconnected');
    const example = source.pipe(map(event => 'Event time: ${event.timeStamp}'));
    const subscribe = example.subscribe(val => console.log(val));
  }
}
