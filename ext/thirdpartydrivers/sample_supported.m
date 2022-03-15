function boards = sample_supported
% <name>_supported fills in a single instance or an array
% of structures with information about PCI boards that may
% be found in a system.  This information is used by getxpcpci.
%
%   VendorID is the number assigned to the vendor of the board
%   or bus adapter for this board.  This is given as a
%   hexadecimal number in string form.  This value is compared
%   with information returned from the target to decide if this
%   device is present.
%
%   DeviceID is the number chosen by the vendor for this specific
%   board or bus adapter.  This is given as a hexadecimal number
%   in string form.  This value is compared with information
%   returned from the target to decide if this device is present.
%
%   SubVendorID is the number assigned to the vendor of this
%   subsystem (the whole board).  Enter the number as a string
%   in hex.  If this is not needed to uniquely identify the board,
%   enter '-1'.
%
%   SubDeviceID is the vendor chosen number assigned to this
%   specific board in the vendor's catalog.  Enter the number as a
%   string in hex.  If this is not needed to uniquely identify the
%   board, enter '-1'.
%
%     NOTE: Some bus interface chips used on PCI boards, such
%     as the PLX-9080 always return a vendor ID of 0x10b5 (==PLX) and
%     a device ID of 9080 or 9050.  For these boards, it is necessary
%     to include SubVendorID and SubDeviceID.
%
%   DeviceName is a string that identifies the specific board.
%
%   VendorName is a string that identifies the vendor of the board.
%
%   DeviceType is a string that indicates the functions that the
%   board performs.  Abbreviations like DI for digital input, etc.
%   are appropriate.  This is only used as a display string.

%   Copyright 2006 The MathWorks, Inc.
%   $Revision: 1.1.6.1 $  $Date: 2006/11/15 15:14:09 $

% An empty return indicates that there are no boards to be
% shown for this file.  Preset to empty and overwrite below.
boards = [];

% An example of two structures for the Commtech serial boards
% is shown below.  If you only have one board, then you can
% stop with boards(1).  If you have more boards, you can continue
% with boards(3), boards(4), etc.

%  boards(1).VendorID   = '18f7'; 
%  boards(1).DeviceID   = '0004'; 
%  boards(1).SubVendorID = '-1';
%  boards(1).SubDeviceID = '-1';
%  boards(1).DeviceName = '422/2-PCI-335'; 
%  boards(1).VendorName = 'Commtech';
%  boards(1).DeviceType = 'Serial Ports';

%  boards(2).VendorID   = '18f7'; 
%  boards(2).DeviceID   = '0002'; 
%  boards(2).SubVendorID = '-1';
%  boards(2).SubDeviceID = '-1';
%  boards(2).DeviceName = '422/4-PCI-335'; 
%  boards(2).VendorName = 'Commtech';
%  boards(2).DeviceType = 'Serial Ports';
 
  return;

