import {NgModule} from '@angular/core';
import {AppComponent} from './app.component';
import {SwitchesComponent} from './switches/switches.component';
import {LinearGaugeComponent} from './linear-gauge/linear-gauge.component';
import {RadialGaugeComponent} from './radial-gauge/radial-gauge.component';
import {WebsocketService} from './websocket.service';
import {RovStateService} from './rovstate.service';
import {IMPORTS} from './app.imports';
import {DECLARATIONS} from './app.declarations';
import {GamepadService} from './gamepad.service';

@NgModule({
  declarations: DECLARATIONS,
  imports: IMPORTS,
  providers: [WebsocketService, RovStateService, GamepadService],
  bootstrap: [AppComponent],
  exports: [
    AppComponent,
    SwitchesComponent,
    LinearGaugeComponent,
    RadialGaugeComponent,
  ]
})
export class AppModule {
}

