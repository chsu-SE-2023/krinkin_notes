package chsu.oakrinkin.components;

import com.vaadin.flow.component.upload.Receiver;
import com.vaadin.flow.component.upload.Upload;

public class FileUpload extends Upload {
    public FileUpload(Receiver receiver) {
        super();
        this.setReceiver(receiver);
        this.setDropAllowed(false);
    }
}
